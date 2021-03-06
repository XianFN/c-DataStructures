#include "sequence.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence()
{
    head = nullptr;
}
template <typename Key, typename Info>
Sequence<Key, Info>::~Sequence()
{
    element *curr=head;
    while (curr!=nullptr) {
        curr=curr->next;
        delete head;
        head=curr;
    }
}
template <typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence &copy)
{
    if (copy.head == nullptr){

        head=nullptr;

    }else{


        element* tmp = copy.head;

        head = new element;
        head->info = tmp->info;
        head->key = tmp->key;
        head->next = nullptr;
        element*  current = head;

        tmp = tmp->next;

        while (tmp != nullptr)
        {
            current->next = new element;
            current = current->next;

            current->info = tmp->info;
            current->key = tmp->key;
            current->next = nullptr;
            tmp = tmp->next;
        }
    }
}
template <typename Key, typename Info>
Sequence<Key, Info> &Sequence<Key, Info>::operator=(const Sequence<Key, Info> &moveObj)
{
    Sequence<Key, Info> temp(moveObj);
    swap(temp.head,head);
    return *this;

}

template <typename Key, typename Info>
Sequence<Key, Info> &Sequence<Key, Info>::operator+=(const Sequence<Key, Info> &newList)
{
    Sequence<Key, Info> *addition = new Sequence<Key, Info>(newList); // make deep copy of passed in list
    if (this->isEmpty())
        head = addition->head;
    else if (addition->isEmpty()) {
        return *this;

    }else{
        element *curr = head;
        while (curr->next != nullptr)
        {
            curr= curr->next;

        }
        curr->next=addition->head;
    }


    // Destroy deep copy
    addition->head = nullptr;
    delete addition;

    return *this;
}
template <typename key, typename info>
Sequence<key, info> operator+(const Sequence<key, info>& addOp2, const Sequence<key, info>& addOp)
{
    Sequence<key, info> result(addOp2); // make deep local copy
    result += addOp;
    return result;
}
template <typename Key, typename Info>
Sequence<Key, Info> &Sequence<Key, Info>::operator-=(const Sequence<Key, Info> &newList)
{
    Sequence<Key, Info> *substract = new Sequence<Key, Info>(newList); // make deep copy of passed in list
    if (this->isEmpty())
        return *this;
    else if (substract->isEmpty()) {
        return *this;

    }else{
        element *curr = substract->head;
        while (curr != nullptr)
        {
            this->deleteElement(curr->key,1);
            curr= curr->next;

        }
    }

    // Destroy deep copy
    substract->head = nullptr;
    delete substract;

    return *this;
}
template <typename key, typename info>
Sequence<key, info> operator-(const Sequence<key, info>& substractOp2, const Sequence<key, info>& substractOp)
{
    Sequence<key, info> result(substractOp2);
    result -= substractOp;
    return result;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::isEmpty(){
    if (head==nullptr) {
        return true;
    }
    return false;
}
template <typename Key, typename Info>
Key Sequence<Key, Info>::getKey(int index){
    if (head!=nullptr) {
        element *curr = head;
        if (index<0) {
            return false;
        }
        while (curr->next != nullptr&&index!=0)
        {
            curr= curr->next;
            index--;

        }
        if (index==0) {
            return curr->key;
        }else{
            return false;
        }

    }


}
template <typename Key, typename Info>
Info Sequence<Key, Info>::getInfo(int index){
    if (head!=nullptr) {
        element *curr = head;
        if (index<0) {
            return false;
        }
        while (curr->next != nullptr&&index!=0)
        {
            curr= curr->next;
            index--;

        }
        if (index==0) {
            return curr->info;
        }else{
            return false;
        }

    }


}
template <typename Key, typename Info>
bool Sequence<Key, Info>::itsNodeEmpty(int index){

    if (head!=nullptr) {
        element *curr = head;
        if (index<0) {
            return false;
        }
        while (curr->next != nullptr&&index!=0)
        {
            curr= curr->next;
            index--;

        }
        if (index==0) {
            if (curr!=nullptr) {
                return true;
            }

        }
        return false;
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
