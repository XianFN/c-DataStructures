#include "Sequence.h"
#include <iostream>
#include <string>
using namespace std;

//autoinden cntr+a, cntr+k,cntr+f
template <typename Key, typename Info>
Sequence<Key, Info>::Sequence()
{
    cout << "F" <<endl;
    head=nullptr;
}
template <typename Key, typename Info>
Sequence<Key, Info>::~Sequence()
{
    delete this;
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
//TODO HACER
    if (head == nullptr)
    {
        return false;
    }
    if (occurance > 1)
    {
        return false;
    }

    element *curr = head;
    while (curr != nullptr)
    {
        if (curr->key == where)
        {
            occurance++;
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
bool Sequence<Key, Info>::insertAtBeg(const Key &newKey, const Info &newInfo){


    if (head == nullptr)
    {
        
        element *ptr = new element();
        ptr->key = newKey;
        ptr->info = newInfo;
        ptr->next =nullptr;;
        cout<<"true"<<endl;
    //    cout<<head->key<<endl;
        return true;
    }else{
       
        element *temp = head->next;
        element *ptr = new element();
        ptr->key = newKey;
        ptr->info = newInfo;
        ptr->next = temp;
        head->next = ptr;
        return true;

    }

}
template <typename Key, typename Info>
    bool Sequence<Key, Info>::insertAtEnd(const Key &newKey, const Info &newInfo){


    if (head == nullptr)
    {
      insertAtBeg(newKey, newInfo);
        
    }else{
        element *curr = head;
        while (curr->next!= nullptr)
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

    element *e = head;
    while (!(e->next->Key == what))
    {
        e = e->next;

        //probablemente mal
    }


    if (!search(what,occurance)){
        return false;
    }

    element* prev = nullptr;
     element* curr = head;
      element* temp = nullptr;
      while (curr){
          if (curr->key == what)
          {

              occurance--;
              if (!occurance)
              {
               if (head==curr)
               {
                   hear=curr->next;
                   temp = curr;
                   curr=head; 
                }else{
                    prev->next = curr->next;
                    temp = curr;
                    curr = curr->next;
                }
                delete temp;
                return true;
               



              }
              
          }
          prev= curr;
          curr=curr->next;
          
      }
      //not necesary   
     // return false;
      


   


}
template <typename Key, typename Info>
bool Sequence<Key, Info>::search(const Key &key){

    if (head== nullptr || occurance < 1){
        return false;
    }
    element* curr=head;

    while (curr)
    {
        if (curr->key == what && !(--occurance))
        {
            return true;
        }
        curr= curr->next;
        
    }
    return false;
    




}