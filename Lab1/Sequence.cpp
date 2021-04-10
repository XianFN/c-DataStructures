#include "Sequence.h"
#include <iostream>
#include <string>

#include <sstream>
using namespace std;

//autoinden cntr+a, cntr+k,cntr+f
template <typename Key, typename Info>
Sequence<Key, Info>::Sequence()
{

    head = nullptr;
}
template <typename Key, typename Info>
Sequence<Key, Info>::~Sequence()
{

    if (head != nullptr) // List is not empty
    {
        element *curr = head;
        element *temp = nullptr;
        while (curr != nullptr) // delete remaining nodes
        {

            temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
}

//using Sequence= Sequence;
template <typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>::merge_pos(Sequence<Key, Info> &seq1, int start_pos1, int len1, Sequence<Key, Info> &seq2, int start_pos2, int len2, int count)
{
}
template <typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>::merge_key(Sequence<Key, Info> &seq1, const Key &start_key1, int start_occ1, int len1, Sequence<Key, Info> &seq2, const Key &start_key2, int start_occ2, int len2, int count)
{
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::insertAfter(const Key &newKey, const Info &newInfo, const Key &where, int occurance)
{
    //CORRECT

    if (head == nullptr)
    {
        return false;
    }
    if (occurance < 1)
    {
        return false;
    }

    element *curr = head;
    while (curr != nullptr)
    {
        if (curr->key == where)
        {
            occurance--;
            if (occurance == 0)
            {
                element *temp = curr->next;
                element *ptr = new element();
                ptr->key = newKey;
                ptr->info = newInfo;
                ptr->next = temp;
                curr->next = ptr;
                return true;
            }
        }
        curr = curr->next;
    }
    return false;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::insertBefore(const Key &newKey, const Info &newInfo, const Key &where, int occurance)
{
    //CORRECT?
    if (head == nullptr)
    {
        return false;
    }
    if (occurance < 1)
    {
        return false;
    }

    element *curr = head;
    if (head->key == where)
    {
        if (occurance == 1)
        {
            element *temp = head;
            element *ptr = new element();
            ptr->key = newKey;
            ptr->info = newInfo;
            ptr->next = temp;
            head = ptr;

            return true;
        }
        else
        {
            occurance--;
        }
    }

    while (curr->next != nullptr)
    {
        if (curr->next->key == where)
        {
            occurance--;
            if (occurance == 0)
            {

                element *temp = curr->next;
                element *ptr = new element();
                ptr->key = newKey;
                ptr->info = newInfo;
                ptr->next = temp;
                curr->next = ptr;
                return true;
            }
        }
        curr = curr->next;
    }
    return false;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::insertAtBeg(const Key &newKey, const Info &newInfo)
{
    //CORRECT
    if (head == nullptr)
    {

        element *ptr = new element();
        ptr->key = newKey;
        ptr->info = newInfo;
        ptr->next = nullptr;
        head = ptr;
        return true;
    }
    else
    {

        element *temp = head;
        element *ptr = new element();
        ptr->key = newKey;
        ptr->info = newInfo;
        ptr->next = temp;
        head = ptr;
        return true;
    }
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::insertAtEnd(const Key &newKey, const Info &newInfo)
{
    //CORRECT
    if (head == nullptr)
    {
        insertAtBeg(newKey, newInfo);
    }
    else
    {
        element *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        element *ptr = new element();
        ptr->key = newKey;
        ptr->info = newInfo;
        ptr->next = nullptr;
        curr->next = ptr;
        return true;
    }
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::deleteElement(const Key &what, int occurance)
{
    //CORRECT

    if (!search(what, occurance))
    {
        return false;
    }

    element *prev = nullptr;
    element *curr = head;
    element *temp = nullptr;
    while (curr)
    {
        if (curr->key == what)
        {

            occurance--;
            if (!occurance)
            {
                if (head == curr)
                {
                    head = curr->next;
                    temp = curr;
                    curr = head;
                }
                else
                {
                    prev->next = curr->next;
                    temp = curr;
                    curr = curr->next;
                }
                delete temp;
                return true;
            }
        }
        prev = curr;
        curr = curr->next;
    }
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::search(const Key &what, int occurance)
{
    //CORRECT

    if (head == nullptr || occurance < 1)
    {
        return false;
    }
    element *curr = head;

    while (curr)
    {
        if (curr->key == what && !(--occurance))
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
template <typename Key, typename Info>
void Sequence<Key, Info>::prinf()
{

    if (head == nullptr)
    {
        cout << "[]" << endl;
    }
    else
    {
        element *curr = head;
        while (curr != nullptr)
        {
            cout << "[" << curr->key << "," << curr->info << "]";

            curr = curr->next;
        }
        cout << endl;
    }
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::AssertEquals(string wantedOutput)
{
    string thisOuput;

    if (head == nullptr)
    {
        thisOuput = "[]";
    }
    else
    {
        element *curr = head;
        stringstream thisOuputSS;
        while (curr != nullptr)
        {

            thisOuputSS << "[" << curr->key << "," << curr->info << "]";

            curr = curr->next;
        }
        thisOuputSS >> thisOuput;
    }

    return thisOuput == wantedOutput;
}