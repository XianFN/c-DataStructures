#include "ring.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


template <typename Key, typename Info>
Ring<Key, Info>::Ring()
{
    tail=head=nullptr;
}
template <typename Key, typename Info>
Ring<Key, Info>::~Ring()
{
    element * temp;
    temp=head;
    if(tail!=nullptr)
        tail->next=nullptr;
    while(temp!=nullptr)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }
    head=tail=nullptr;
}

template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::search(const Key& where, int occurance){
    Key keyToCompare;
    int occ=0;
    for (Iterator itr= this->begin();itr != end(); itr++){
        itr.getKey(keyToCompare);
        if (keyToCompare == where) {
            occ++;
        }
        if (occ == occurance) {
            return itr(this);
        }
        return end(); // return Iterator(this);
    }
    /* another way
    int occ=0;
    for (element* etr =any; etr !=nullptr; etr=etr->next){

        if (etr->key == where) {
            occ++;
        }
        if (occ == occurance) {
            return Iterator(etr);
        }
        return Iterator();
    }
    */


}
template <typename Key, typename Info>
bool Ring<Key, Info>::search2(const Key& key, int occurance){

    //TODO comprobar
    element * curr=any;
    if (any== nullptr) {
        return false;
    }
    do {
        if (curr->key==key) {
            occurance--;
        }
        if (occurance==0) {
            return true;
        }

        curr=curr->next;
    } while (curr!=any);
    return false;

}
template <typename Key, typename Info>
bool Ring<Key, Info>:: remove(const Key& what, int occurance){

    element *curr=any;
    if (curr== nullptr) {
        return false;
    }
    if (curr->key == what) {
        occurance--;
        if (occurance==0) {
            if (curr->next==any) {
                delete curr;
                any= nullptr;
                return true;

            }
            do {
                curr= curr->next;
            } while (curr->next!=any);
            element* elementToRemove = curr->next;
            curr->next= curr->next->next;
            delete elementToRemove;
            return true;

        }

    }
    do {
        if (curr->next->key == what) {
            occurance--;
        }
        curr=curr->next;
    } while (curr !=any && occurance>0);
    if (occurance==0) {
        element* elementToRemove = curr->next;
        curr->next= curr->next->next;
        delete elementToRemove;
        return true;

    }else{
        return false;
    }


}


template <typename Key, typename Info>
bool Ring<Key, Info>::insertAfter(const Key& newKey, const Info& newInfo, const Key& where, int occurance=1){

    if (where == end()) {  //where == Iterator(this)
        return false;
    }
    if (where.owner != this) { // the iterator is from another Ring
        return false;
    }
    element *nptr = new element(newKey,newInfo);
    element *etr = where.ptr;
    nptr->next = etr->next;
    etr->next = nptr;
    return true;

}
template <typename Key, typename Info>
void Ring<Key, Info>::print(bool direct){
      //TODO comprobar
    element * curr;
    if (direct) {
        curr=head;
        if (curr!= nullptr) {
            do {
                cout << curr->info <<endl;

                curr=curr->next;
            } while (curr!=head);
        }
    }else{
        curr=tail;
        if (curr!= nullptr) {
            do {
                cout << curr->info <<endl;

                curr=curr->prev;
            } while (curr!=tail);
        }
    }

}
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::begin(){
    return Iterator(head);
}
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::end(){
    return Iterator(tail);
}



/*seach in privae if we want to use the element struct
template <typename Key, typename Info>
bool Ring<Key, Info>::search (const Key& key, int occurance) {
    element *c, *p;
    return search (c, p, key, occurance);
}
template <typename Key, typename Info>
bool Ring<Key, Info>::search (element& curr, element& prev, const Key& key, int occurance){
    if (!any)
        return false;
    curr = any->next;
    prev = any;
}
*/

//TODO añadir que si ptr es null en todos los casos
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::Iterator::operator++(int){

    Iterator curr(*this);
    if (ptr!=nullptr) {
        ptr = ptr->next;
    }
    return curr;

}

template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator& Ring<Key, Info>::Iterator::operator++(){


    if (ptr!=nullptr) {
        ptr = ptr->next;
    }
    return *this;
}
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::Iterator::operator+(int i){

//  Iterator curr = *this;
    Iterator curr(*this);
    for(int j=0; j<i; j++)
        curr++;
    return curr;
}
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator& Ring<Key, Info>::Iterator::operator--(){


    Iterator curr(*this);
    ptr=ptr->prev;
    return curr;
}
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator& Ring<Key, Info>::Iterator::operator--(int){


    ptr=ptr->prev;
    return *this;
}
template <typename Key, typename Info>
Info& Ring<Key, Info>::Iterator::operator*(){


    return ptr->info;
}


template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::operator==(const Iterator & other){

 return ptr==other.ptr;

}
template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::operator!=(const Iterator &other){

return ptr!=other.ptr;
}
template <typename Key, typename Info>
Key& Ring<Key, Info>::Iterator::getKey(){


    return ptr->key;
}
template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::setKey(const Key &newkey){

    this->ptr->key=newkey;
    return true;
}
template <typename Key, typename Info>
bool Ring<Key, Info>::AssertEquals(string wantedOutput)
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


