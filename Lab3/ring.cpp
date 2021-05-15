#include "ring.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


template <typename Key, typename Info>
Ring<Key, Info>::Ring()
{
    head=nullptr;
}
template <typename Key, typename Info>
Ring<Key, Info>::~Ring()
{


    element * temp;
    temp=head;

    if (head!=nullptr) {
         element * last= head->prev;

    while(temp->next!=last)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }
    head=head->prev=nullptr;
    }

}
template<typename Key, typename Info>
Ring<Key,Info>::Ring(const Ring<Key,Info> & copy)
{
    head=nullptr;
    typename Ring<Key, Info>::const_Iterator it1;
    it1=copy.beginConst(true);
    int size1=copy.size();
    for (int i=0;i<size1 ;i++ ) {

        insertAtEnd(it1.getKey(),it1.getInfo(),true);
        it1++;
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
    if(head!=nullptr &&& head->prev!=nullptr){
           head->prev->next=nullptr;
    }else{
    }

    while(aux!=nullptr)
    {

        aux = aux->next;
        delete head;
        head = aux;
    }
    head=nullptr;

    typename Ring<Key, Info>::const_Iterator it1;
    it1=copy.beginConst(true);
    int size1=copy.size();

    for (int i=0;i<size1 ;i++ ) {

        insertAtEnd(it1.getKey(),it1.getInfo(),true);
        it1++;
    }

    return *this;
}
template<typename Key, typename Info>
bool Ring<Key,Info>::operator==(const Ring<Key,Info> &other){
    bool same = true;
    typename Ring<Key, Info>::const_Iterator it1;
    typename Ring<Key, Info>::const_Iterator it2;
    it1=beginConst(true);
    it2=other.beginConst(true);

    int size1=size();
    if (size1!=other.size()) {
        return false;
    }
    for (int i=0;i<size1 ;i++ ) {



        if(it1.getKey!=it2.getKey() || it1.getInfo!=it2.getInfo()){
            same = false;
        }
        it1++;
        it2++;

    }
    return same;
}
template<typename Key, typename Info>
bool Ring<Key,Info>::operator!=(const Ring<Key,Info> &other){
    return !(*this==other);
}

template <typename key, typename info>
Ring<key, info> operator+(const Ring<key, info>&newRing,const Ring<key, info>&newRing2){
    Ring<key, info> result(newRing);

    result += newRing2;
    return result;
}

template<typename Key, typename Info>
Ring<Key,Info> & Ring<Key,Info>::operator++(){
    if(head)
    {
        head=head->next;
    }
    return *this;
}
template<typename Key, typename Info>
Ring<Key,Info> & Ring<Key,Info>::operator++(int){
    Ring a(*this);
    if(head)
    {
        head=head->next;
    }
    return a;
}
template <typename key, typename info>
Ring<key, info> operator-(const Ring<key, info>&subRing,const Ring<key, info>&subRing2){
    Ring<key, info> result(subRing);
    result -= subRing2;
    return result;


}
template<typename Key, typename Info>
Ring<Key,Info> & Ring<Key,Info>::operator--(){
    if(head)
    {
        head=head->prev;
    }
    return *this;
}
template<typename Key, typename Info>
Ring<Key,Info> & Ring<Key,Info>::operator--(int){
    Ring a(*this);
    if(head)
    {
        head=head->prev;
    }
    return a;
}

template<typename Key, typename Info>
Ring<Key,Info> & Ring<Key,Info>::operator+= (const Ring<Key, Info>&newRing){

    if (newRing.isEmpty()) {
        return *this;

    }else{
        typename Ring<Key, Info>::const_Iterator it2;
        it2=newRing.beginConst(true);
        if (!it2.isEmpty()) {
            int size2=newRing.size();
            for (int i=0;i<size2 ;i++ ) {

                insertAtEnd(it2.getKey(),it2.getInfo(),true);
                it2++;
            }
        }
        return *this;
    }

}

template<typename Key, typename Info>
Ring<Key,Info> & Ring<Key,Info>::operator-= (const Ring<Key, Info>&subRing){
    if (this->isEmpty())
        return *this;
    else if (subRing.isEmpty()) {
        return *this;

    }else{
        typename Ring<Key, Info>::const_Iterator it2;
        it2=subRing.beginConst(true);
        if (!it2.isEmpty()) {
            int size2=subRing.size();
            for (int i=0;i<size2 ;i++ ) {


                remove(it2.getKey(),1,true);
                it2++;
            }
        }
        return *this;
    }
}

template <typename Key, typename Info>
int Ring<Key,Info>::size() const {
    int count =0;
    if (head!=nullptr) {


        Ring<Key,Info> tempRing;

        element * temp = head;
        do
        {
            count++;
            temp=temp->next;
        }while(temp!=head);

    }
    return count;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::isEmpty() const{
    if (head==nullptr) {
        return true;
    }
    return false;
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
        return end();
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
int Ring<Key, Info>::search(const Key& key)const{

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

    //  curr= direct ? curr->next : curr->prev;


    if (head== nullptr) {
        return false;
    }
    int totalKey= search(what);
    if (totalKey==0||occurance==0) {
        return false;
    }
    if (occurance>=totalKey) {
        occurance= occurance%totalKey;
        if (occurance==0) {
            occurance=totalKey;
        }

    }


    element * curr;
    curr=  direct ? head : head->prev;
    if (curr->key == what) {
        if (occurance==1) {
            if (direct) {
                if (curr->next==head) {
                    delete curr;
                    head= nullptr;
                    return true;

                }

                element* elementToRemove = curr;
                head->next->prev= head->prev;
                head->prev->next= head->next;
                head=head->next;

                delete elementToRemove;

                return true;
            }else{
                if (curr->next==head->prev) {
                    delete curr;
                    head= nullptr;

                    return true;

                }

                element* elementToRemove = curr;
                head->prev->prev->next= head;
                head->prev= head->prev->prev;


                delete elementToRemove;

                return true;
            }

        }

    }
    int sizeOfRing= size();
    while(sizeOfRing>0 && occurance>0) {
        if (curr->key==what) {
            occurance--;
            if (occurance!=0) {
                curr= direct ? curr->next : curr->prev;


            }
        }else {
            curr= direct ? curr->next : curr->prev;

        }
        sizeOfRing--;

    }
    if (direct) {
        if (curr==head->prev) {

            element* elementToRemove = curr;
            curr->prev->next= head;

            head->prev= head->prev->prev;


            delete elementToRemove;

            return true;

        }

        element* elementToRemove = curr;
        curr->prev->next= curr->next;
        curr->next->prev= curr->prev;

        delete elementToRemove;

        return true;
    }else{

        if (curr==head) {

            element* elementToRemove = curr;
            head->next->prev= head->prev;
            head->prev->next= head->next;
            head=curr->next;

            delete elementToRemove;

            return true;


        }

        element* elementToRemove = curr;
        curr->prev->next= curr->next;
        curr->next->prev= curr->prev;

        delete elementToRemove;

        return true;

    }


}
template <typename Key, typename Info>
bool Ring<Key, Info>::insertAtBeg (const Key& newKey, const Info& newInfo,bool direct){


    if (!direct) {

        return insertAtEnd(newKey,newInfo,true);
    }else{
        element* temp = new element;

        temp->key = newKey;
        temp->info = newInfo;

        if(head==nullptr)
        {
            temp->next = temp;
            temp->prev = temp;
            head=temp;
        }else{

            temp->next = head;
            temp->prev = head->prev;
            head->prev->next=temp;
            head->prev=temp;
            head=temp;
        }
        return true;
    }
}
template <typename Key, typename Info>
bool Ring<Key, Info>::insertAtBeg (Iterator what,bool direct){


    if (!direct) {

        return insertAtEnd(what.getKey(),what.getInfo(),true);
    }else{
        element* temp = new element;

        temp->key = what.getKey();
        temp->info =what.getInfo();

        if(head==nullptr)
        {
            temp->next = temp;
            temp->prev = temp;
            head=temp;
        }else{

            temp->next = head;
            temp->prev = head->prev;
            head->prev->next=temp;
            head->prev=temp;
            head=temp;
        }
        return true;
    }
}
template <typename Key, typename Info>
bool Ring<Key, Info>::insertAtEnd (const Key& newKey, const Info& newInfo,bool direct){

    if (!direct) {

        return insertAtBeg(newKey,newInfo,true);
    }else{
        element* temp=new element ;
        temp->key=newKey;
        temp->info=newInfo;



        if(head==nullptr)
        {
            temp->next = temp;
            temp->prev = temp;
            head=temp;
        }else{

            temp->next = head;
            temp->prev = head->prev;
            head->prev->next=temp;
            head->prev=temp;

        }
        return true;
    }
}

template <typename Key, typename Info>
bool Ring<Key, Info>::insertAtEnd (Iterator what,bool direct){


    if (!direct) {

        return insertAtBeg(what.getKey(),what.getInfo(),true);
    }else{
        element* temp = new element;

        temp->key = what.getKey();
        temp->info =what.getInfo();

        if(head==nullptr)
        {
            temp->next = temp;
            temp->prev = temp;
            head=temp;
        }else{

            temp->next = head;
            temp->prev = head->prev;
            head->prev->next=temp;
            head->prev=temp;


        }
        return true;
    }
}
template <typename Key, typename Info>
bool Ring<Key, Info>::insertAfter(const Key& newKey, const Info& newInfo, const Key& where, int occurance,bool direct){

    if (head==nullptr) {
        return false;
    }
    int totalKey= search(where);
    if (totalKey==0||occurance==0) {
        return false;
    }
    if (occurance>=totalKey) {
        occurance= occurance%totalKey;
        if (occurance==0) {
            occurance=totalKey;
        }

    }


    element * curr;
    curr=  direct ? head : head->prev;

    while (occurance!=0||curr->key!=where) {

        if (curr->key==where) {
            occurance--;
            if (occurance!=0) {
                curr= direct ? curr->next : curr->prev;


            }
        }else{
            curr= direct ? curr->next : curr->prev;
        }

    };
    if (curr==head->prev) {

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


    if (head==nullptr) {
        return false;
    }
    int totalKey= search(where);
    if (totalKey==0||occurance<1) {
        return false;
    }
    if (occurance>=totalKey) {
        occurance= occurance%totalKey;
        if (occurance==0) {
            occurance=totalKey;
        }
    }




    element * curr;
    curr=  direct ? head : head->prev;

    while (occurance!=0||curr->key!=where) {

        if (curr->key==where) {
            occurance--;
            if (occurance!=0) {
                curr= direct ? curr->next : curr->prev;

            }
        }else{
            curr= direct ? curr->next : curr->prev;
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
bool Ring<Key, Info>::insertAfter(const Key& newKey, const Info& newInfo, Iterator where,bool direct){

    if (where == end(true)) {
        return false;
    }
    if (where.owner != this) { // the iterator is from another Ring
        return false;
    }
    if (!direct) {
        insertBefore(newKey,newInfo,where,!direct);
    }else{

    element* nptr=new element ;
    nptr->key=newKey;
    nptr->info=newInfo;

    element *etr = where.ptr;
    nptr->prev=etr;
    nptr->next = etr->next;
    etr->next->prev=nptr;
    etr->next = nptr;
    return true;
}
}

template <typename Key, typename Info>
bool Ring<Key, Info>::insertBefore(const Key& newKey, const Info& newInfo, Iterator where, bool direct){

    if (where == end(true)) {
        return false;
    }
    if (where.owner != this) { // the iterator is from another Ring
        return false;
    }

    if (!direct) {
        insertAfter(newKey,newInfo,where,!direct);
    }else{


        element* nptr=new element ;
        nptr->key=newKey;
        nptr->info=newInfo;

        element *etr = where.ptr;
        nptr->next = etr;
        nptr->prev=etr->prev;
        etr->prev->next=nptr;
        etr->prev = nptr;
        return true;
    }

}
template <typename Key, typename Info>
bool Ring<Key, Info>::insertBefore(const Key& newKey, const Info& newInfo, const_Iterator where, bool direct){

    if (where == endConst()) {
        return false;
    }

    if (!direct) {
        insertAfter(newKey,newInfo,where,!direct);
    }else{


    element* nptr=new element ;
    nptr->key=newKey;
    nptr->info=newInfo;

    element *etr = where.ptr;
    nptr->next = etr;
    nptr->prev=etr->prev;
    etr->prev->next=nptr;
    etr->prev = nptr;
    return true;
    }

}
template <typename Key, typename Info>
void Ring<Key, Info>::print(bool direct){
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
        curr=head->prev;
        if (curr!= nullptr) {
            do {
                cout << curr->info <<endl;

                curr=curr->prev;
            } while (curr!=head->prev);
        }
    }

}
template <typename Key, typename Info>
void Ring<Key, Info>::print2(bool direct){
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
        curr=head->prev;
        if (curr!= nullptr) {
            do {
                cout <<"["<< curr->key<<","<<curr->info<<"]";

                curr=curr->prev;
            } while (curr!=head->prev);
            cout<<endl;
        }
    }

}



template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator associeteWith(const Ring<Key, Info>&newIt ){

    typename Ring<Key, Info>::Iterator it1;
    it1=newIt.begin();


    return it1;
}
template <typename Key, typename Info>
Ring<Key, Info>::Iterator::Iterator(const Ring<Key, Info>&newIt ){
    this->ptr=newIt.head;
}

template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::begin(bool direct){
    if (!direct) {
        end(!direct);
    }else{
        Iterator aux;
        if (head!= nullptr){
            aux.ptr=head;
        }

        return aux;
    }
}
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::end(bool direct){
        if (!direct) {
            begin(!direct);
        }else{
            Iterator aux;
            if (head!= nullptr){
                aux.ptr=head->prev;
            }
            return aux;

        }
}



template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::Iterator::operator++(int){

    Iterator curr(*this);
    if (ptr!=nullptr) {
        ptr = ptr->next;
    }
    return *this;

}

template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator& Ring<Key, Info>::Iterator::operator++(){

    Iterator a(*this);
    if (ptr!=nullptr) {
        ptr = ptr->next;
    }
    return a;
}
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::Iterator::operator+(int i){

    //  Iterator curr = *this;
    Iterator curr(*this);
    if (ptr!=nullptr) {
        for(int j=0; j<i; j++)
            curr++;
    }
    return curr;
}
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator& Ring<Key, Info>::Iterator::operator--(){


    Iterator curr(*this);
    if (ptr!=nullptr) {
        ptr=ptr->prev;
    }
    return curr;
}
template <typename Key, typename Info>
typename Ring<Key, Info>::Iterator& Ring<Key, Info>::Iterator::operator--(int){

    if (ptr!=nullptr) {
        ptr=ptr->prev;
    }
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
Info& Ring<Key, Info>::Iterator::getInfo(){


    return ptr->info;
}
template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::setKey(const Key &newkey){

    this->ptr->key=newkey;
    return true;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::setInfo(const Info &newInfo){

    this->ptr->info=newInfo;
    return true;
}



//----------------------------------------------------CONST ITERATOR---------------------------------------------------------------
template <typename Key, typename Info>
typename Ring<Key, Info>::const_Iterator associeteWith(const Ring<Key, Info>&newIt ){

    typename Ring<Key, Info>::const_Iterator it1;
    it1=newIt.beginConst(true);

    return it1;
}
template <typename Key, typename Info>
Ring<Key, Info>::const_Iterator::const_Iterator(const Ring<Key, Info>&newIt ){
    this->ptr=newIt.head;

}

template <typename Key, typename Info>
typename Ring<Key, Info>::const_Iterator Ring<Key, Info>::beginConst(bool direct) const{
    if (!direct) {
        endConst(!direct);
    }else{
    const_Iterator aux;
    aux.ptr=head;
    return aux;
    }
}
template <typename Key, typename Info>
typename Ring<Key, Info>::const_Iterator Ring<Key, Info>::endConst(bool direct) const{
        if (!direct) {
            endConst(!direct);
        }else{
    const_Iterator aux;
    aux.ptr=head->prev;
    return aux;
        }
}





template <typename Key, typename Info>
const typename Ring<Key, Info>::const_Iterator Ring<Key, Info>::const_Iterator::operator++(int){

    const_Iterator curr;
    if (ptr!=nullptr) {
        ptr = ptr->next;
    }
    return *this;

}

template <typename Key, typename Info>
const typename Ring<Key, Info>::const_Iterator& Ring<Key, Info>::const_Iterator::operator++(){

    const_Iterator a;
    if (ptr!=nullptr) {
        ptr = ptr->next;
    }
    return a;
}
template <typename Key, typename Info>
const typename Ring<Key, Info>::const_Iterator Ring<Key, Info>::const_Iterator::operator+(int i){

    //  Iterator curr = *this;
    const_Iterator curr;
    if (ptr!=nullptr) {
        for(int j=0; j<i; j++)
            curr++;
    }
    return curr;
}
template <typename Key, typename Info>
const typename Ring<Key, Info>::const_Iterator& Ring<Key, Info>::const_Iterator::operator--(){


    const_Iterator curr;
    if (ptr!=nullptr) {
        ptr=ptr->prev;
    }
    return curr;
}
template <typename Key, typename Info>
const typename Ring<Key, Info>::const_Iterator& Ring<Key, Info>::const_Iterator::operator--(int){

    if (ptr!=nullptr) {
        ptr=ptr->prev;
    }
    return *this;
}
template <typename Key, typename Info>
const Info& Ring<Key, Info>::const_Iterator::operator*(){


    return ptr->info;
}


template <typename Key, typename Info>
bool Ring<Key, Info>::const_Iterator::operator==(const const_Iterator & other){

    return ptr==other.ptr;

}
template <typename Key, typename Info>
bool Ring<Key, Info>::const_Iterator::operator!=(const const_Iterator &other){

    return ptr!=other.ptr;
}
template <typename Key, typename Info>
const Key& Ring<Key, Info>::const_Iterator::getKey(){


    return ptr->key;
}
template <typename Key, typename Info>
const Info& Ring<Key, Info>::const_Iterator::getInfo(){


    return ptr->info;
}
template <typename Key, typename Info>
bool Ring<Key, Info>::const_Iterator::setKey(const Key &newkey){

    this->ptr->key=newkey;
    return true;
}
template <typename Key, typename Info>
bool Ring<Key, Info>::const_Iterator::setInfo(const Info &newInfo){

    this->ptr->info=newInfo;
    return true;
}
template <typename Key, typename Info>
bool Ring<Key, Info>::const_Iterator::isEmpty(){


    return ptr==nullptr;
}
template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::isEmpty(){


    return ptr==nullptr;
}


