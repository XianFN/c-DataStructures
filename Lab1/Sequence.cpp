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
template <typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence &copy)
{
    this->head = nullptr;
    this->head = copy.head;
}
template <typename Key, typename Info>
Sequence<Key, Info> &Sequence<Key, Info>::operator=(const Sequence<Key, Info> &moveObj)
{

    //swap(moveObj.head,this);
    //this->~Sequence();

    if (moveObj.head==nullptr )
    {
       return *this;
    }
    
    element *headptr = moveObj.head;
    head->key = headptr->key;
    head->info = headptr->info;
    head->next = headptr->next;

    element *curr = head;

    element *temp;

    while (headptr->next != nullptr)
    {

        temp->info = headptr->info;
        temp->next = headptr->next;
        temp->key = headptr->key;

        curr->next = temp;

        headptr = headptr->next;
    }

    return *this;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::merge_pos(Sequence<Key, Info> &seq1, int start_pos1, int len1, Sequence<Key, Info> &seq2, int start_pos2, int len2, int count)
{
   if (count > 0  )
    {
        

    element *currSeq1 = seq1.head;
    element *currSeq2 = seq2.head;
    

    while (start_pos1 != 0 && currSeq1 != nullptr)
    {
        currSeq1 = currSeq1->next;
        start_pos1--;
    }
    while (start_pos2 != 0 && currSeq2 != nullptr)
    {
        currSeq2 = currSeq2->next;
        start_pos2--;
    }

    while (count != 0)
    {

        int lenght1 = len1;
        int length2 = len2;
        while (lenght1 != 0 && currSeq1 != nullptr)
        {

            this->insertAtEnd(currSeq1->key, currSeq1->info);

            currSeq1 = currSeq1->next;
            lenght1--;
        }

        while (length2 != 0 && currSeq2 != nullptr)
        {

            this->insertAtEnd(currSeq2->key, currSeq2->info);

            currSeq2 = currSeq2->next;
            length2--;
        }

        count--;
    }
    }
}
template <typename Key, typename Info>
void Sequence<Key, Info>::merge_key(Sequence<Key, Info> &seq1, const Key &start_key1, int start_occ1, int len1, Sequence<Key, Info> &seq2, const Key &start_key2, int start_occ2, int len2, int count)
{
     if (count > 0  )
    {
        
    element *currSeq1 = seq1.head;
    element *currSeq2 = seq2.head;

    int originalOcc1 = start_occ1;
    int originalOcc2 = start_occ2;
   

    while (start_occ1 != 0 && currSeq1 != nullptr)
    {
        if (currSeq1->key == start_key1)
        {
            start_occ1--;
        }
        if (start_occ1 != 0)
        {
            currSeq1 = currSeq1->next;
        }
    }
    while (start_occ2 != 0 && currSeq2 != nullptr)
    {
        if (currSeq2->key == start_key2)
        {
            start_occ2--;
        }

        if (start_occ2 != 0)
        {
            currSeq2 = currSeq2->next;
        }
    }

    while (count != 0)
    {

        int lenght1 = len1;
        int length2 = len2;
        while (start_occ1 == 0 && lenght1 != 0 && currSeq1 != nullptr && originalOcc1 > 0)
        {

            this->insertAtEnd(currSeq1->key, currSeq1->info);

            currSeq1 = currSeq1->next;
            lenght1--;
        }

        while (start_occ2 == 0 && length2 != 0 && currSeq2 != nullptr && originalOcc2 > 0)
        {

            this->insertAtEnd(currSeq2->key, currSeq2->info);

            currSeq2 = currSeq2->next;
            length2--;
        }

        count--;
    }
    }
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::insertAfter(const Key &newKey, const Info &newInfo, const Key &where, int occurance)
{

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