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
template<typename Key, typename Info>
Ring<Key,Info>::Ring(const Ring<Key,Info> & copy)
{
    head=tail=nullptr;
    element * temp = copy.head;
    while (temp)
    {
        this->insertAtEnd(temp->key, temp->info,true);
        if(temp==copy.tail)
            break;
        temp=temp->next;
    }
}

template<typename Key, typename Info>
Ring<Key,Info> & Ring<Key,Info>::operator=(const Ring<Key,Info> &copy)
{
    if(&copy==this){
        return *this;
    }

    element * aux;
    aux=head;
    if(tail!=nullptr)
        tail->next=nullptr;
    while(aux!=nullptr)
    {
        aux = aux->next;
        delete head;
        head = aux;
    }
    head=tail=nullptr;


    element * temp = copy.head;
    while (temp)
    {
        this->insertAtEnd(temp->key, temp->info,true);
        if(temp==copy.tail)
            break;
        temp=temp->next;
    }

    return *this;
}


template <typename Key, typename Info>
void Ring<Key,Info>::reverse()
{
   // print2(true);
    if (head!=nullptr) {


        Ring<Key,Info> tempRing;

        element * temp = head;
        while(temp!=tail)
        {
            tempRing.insertAtBeg(temp->key,temp->info,true);

            temp=temp->next;
        }
        tempRing.insertAtBeg(temp->key,temp->info,true);

        *this=tempRing;
    }
   // print2(true);
}

template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::search3(const Key& where, int occurance){
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
int Ring<Key, Info>::search(const Key& key){

    if (head==nullptr) {
        return 0;
    }
    element * curr=head;
    int count=0;
    do {
        if (curr->key==key) {
            count++;
        }
        curr=curr->next;
    } while (curr!=head);
    return count;

}


template <typename Key, typename Info>
bool Ring<Key, Info>::search2(const Key& key, int occurance){

    //TODO comprobar
    element * curr=head;
    if (head== nullptr) {
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
    } while (curr!=head);
    return false;

}
template <typename Key, typename Info>
bool Ring<Key, Info>:: remove(const Key& what, int occurance,bool direct){




    if (head== nullptr) {
        return false;
    }
    if (!direct) {
        reverse();
    }

    element *curr=head;
    if (curr->key == what) {
        occurance--;
        if (occurance==0) {
            if (curr->next==head) {
                delete curr;
                head= nullptr;
                if (!direct) {
                    reverse();
                }

                return true;

            }
            do {
                curr= curr->next;
            } while (curr->next!=head);
            element* elementToRemove = curr->next;
            curr->next= curr->next->next;
            delete elementToRemove;
            if (!direct) {
                reverse();
            }
            return true;

        }

    }
    do {
        if (curr->next->key == what) {
            occurance--;
        }
        curr=curr->next;
    } while (curr !=head && occurance>0);
    if (occurance==0) {
        element* elementToRemove = curr->next;
        curr->next= curr->next->next;
        delete elementToRemove;
        if (!direct) {
            reverse();
        }
        return true;

    }else{
        if (!direct) {
            reverse();
        }
        return false;
    }


}
template <typename Key, typename Info>
bool Ring<Key, Info>::insertAtBeg (const Key& newKey, const Info& newInfo,bool direct){

    if (!direct) {
        cout<<"ff"<<endl;

        return insertAtEnd(newKey,newInfo,true);
    }else{
        element* temp = new element;

        temp->key = newKey;
        temp->info = newInfo;

        if(head==nullptr)
        {
            temp->next = temp;
            temp->prev = temp;
            head=tail=temp;
        }else{

            temp->next = head;
            temp->prev = tail;
            tail->next=temp;
            head->prev=temp;
            head=temp;
        }
        return true;
    }
}
template <typename Key, typename Info>
bool Ring<Key, Info>::insertAtEnd (const Key& newKey, const Info& newInfo,bool direct){

    if (!direct) {
        cout<<"ff"<<endl;

        return insertAtBeg(newKey,newInfo,true);
    }else{
        element* temp=new element ;
        temp->key=newKey;
        temp->info=newInfo;



        if(head==nullptr)
        {
            temp->next = temp;
            temp->prev = temp;
            head=tail=temp;
        }else{

            temp->next = head;
            temp->prev = tail;
            tail->next=temp;
            head->prev=temp;
            tail=temp;

        }
        return true;
    }
}
template <typename Key, typename Info>
bool Ring<Key, Info>::insertAfter(const Key& newKey, const Info& newInfo, const Key& where, int occurance,bool direct){

    cout <<"f"<<endl;
    if (head==nullptr) {
        return false;
    }
    int totalKey= search(where);
    if (totalKey==0||occurance==0) {
    cout <<"fff"<<"total: "<<totalKey<<endl;
        return false;
    }
    if (occurance>=totalKey) {
        occurance= occurance%totalKey;
    }

    cout<<"ocurrance:  " <<occurance<<"total: "<<totalKey<<endl;
    //do
    if (!direct) {
        cout<<"Reverse1"<<endl;
        occurance= totalKey-occurance+1;
      //  reverse();
    }
    cout<<"ocurrance:  " <<occurance<<"total: "<<totalKey<<endl;

    element * curr=head;

    while (occurance!=0||curr->key!=where) {

        if (curr->key==where) {
            occurance--;
            if (occurance!=0) {
                curr=curr->next;

            }
        }else{
            curr=curr->next;
        }

    };
    if (curr==tail) {

                  insertAtEnd(newKey,newInfo,true);

    }else{
    element* temp=new element ;
    temp->key=newKey;
    temp->info=newInfo;


    temp->next=curr->next;
    temp->prev=curr;


    curr->next->prev=temp;
    curr->next=temp;


    }


       return true;


}

template <typename Key, typename Info>
bool Ring<Key, Info>::insertBefore(const Key& newKey, const Info& newInfo, const Key& where, int occurance,bool direct){


    cout <<"f"<<endl;
    if (head==nullptr) {
        return false;
    }
    int totalKey= search(where);
    if (totalKey==0||occurance<1) {
    cout <<"fff"<<"total: "<<totalKey<<endl;
        return false;
    }
    if (occurance>=totalKey) {
        occurance= occurance%totalKey;
    }

    cout<<"ocurrance:  " <<occurance<<"total: "<<totalKey<<endl;
    //do
    if (!direct) {
        cout<<"Reverse1"<<endl;
     int   occurance2= totalKey-occurance+1;
     cout<<"ocurrance2:  " <<occurance2<<"total: "<<totalKey<<endl;

      //  reverse();
    }

    element * curr=head;

    while (occurance!=0||curr->key!=where) {

        if (curr->key==where) {
            occurance--;
            if (occurance!=0) {
                curr=curr->next;

            }
        }else{
            curr=curr->next;
        }

    };
    if (curr==head) {

                  insertAtBeg(newKey,newInfo,true);

    }else{
    element* temp=new element;
    temp->key=newKey;
    temp->info=newInfo;


    curr->prev->next=temp;
    temp->next=curr;
    temp->prev=curr->prev;

    curr->prev=temp;

    }


       return true;


}

template <typename Key, typename Info>
bool Ring<Key, Info>::insertAfter(const Key& newKey, const Info& newInfo, Iterator where){

    if (where == end()) {  //where == Iterator(this)
        return false;
    }
    if (where.owner != this) { // the iterator is from another Ring
        return false;
    }

    element* nptr=new element ;
    nptr->key=newKey;
    nptr->info=newInfo;

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
void Ring<Key, Info>::print2(bool direct){
    //TODO comprobar
    if (head==nullptr) {
        cout<<"[]"<<endl;
    }
    element * curr;
    if (direct) {
        curr=head;
        if (curr!= nullptr) {
            do {
                cout <<"["<< curr->key<<","<<curr->info<<"]";

                curr=curr->next;
            } while (curr!=head);
            cout<<endl;
        }
    }else{
        curr=tail;
        if (curr!= nullptr) {
            do {
                cout <<"["<< curr->key<<","<<curr->info<<"]";

                curr=curr->prev;
            } while (curr!=tail);
              cout<<endl;
        }
    }

}
/*
template <typename Key, typename Info>
Ring<Key, Info>::Iterator::Iterator(){
   ptr=nullptr;
}
*/
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::begin(){

    return Iterator(head,this);
}
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::end(){
    return Iterator(tail,this);
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


