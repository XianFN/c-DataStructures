#ifndef RING_H
#define RING_H
#include <iostream>
#include <string>


template <typename Key, typename Info>
class Ring {
    // duplicates are allowed
private:
    struct element
    {
        Key key;
        Info info;
        element *next;
        element *prev;
    };
    element *head;
    element *tail;

public:
    class Iterator {

        element* ptr;
        Ring<Key, Info>* owner;
        Iterator(element* xtr,Ring<Key, Info>*otr):ptr(xtr){
            owner = otr;
        }
    public:
        Iterator(Ring<Key, Info>*otr=nullptr): ptr(nullptr){
            owner = otr;
        }


        Info& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator& operator--(int);
        Iterator operator+(int);
        Key& getKey();
        Info& getInfo();
        bool setKey(const Key&);
        bool setInfo(const Info&);
        bool operator==(const Iterator &other);
        bool operator!=(const Iterator &other);
        Iterator (const Ring<Key, Info>&);
        Iterator associeteWith (const Ring<Key, Info>&);
        friend Ring<Key, Info>;
    };
    class const_Iterator {
        const element* ptr;

    public:
        const_Iterator (): ptr(nullptr){

        }
        const Info& operator*();
        const const_Iterator & operator++();
        const const_Iterator operator++(int);
        const const_Iterator& operator--();
        const const_Iterator& operator--(int);
        const const_Iterator operator+(int);
        const Key& getKey();
        const Info& getInfo();
        bool setKey(const Key&);
        bool setInfo(const Info&);
        bool isEmpty();


        bool operator==(const Iterator &);
        bool operator!=(const Iterator &);
        const_Iterator (const Ring<Key, Info>&newIt );
        const_Iterator associeteWith (const Ring<Key, Info>&);
        friend Ring<Key, Info>;
    };
    Ring();
    ~Ring();
    Ring (const Ring<Key, Info>&);
    Ring<Key, Info>& operator= (const Ring<Key, Info>&copy);
    Ring<Key, Info>& operator++ ();
    Ring<Key, Info>& operator++ (int);
    Ring<Key, Info>& operator+= (const Ring<Key, Info>&newRing);
    Ring<Key, Info>& operator-- ();
    Ring<Key, Info>& operator-- (int);
    Ring<Key, Info>& operator-= (const Ring<Key, Info>&subRing);
    template <typename key, typename info>
    friend  Ring<key, info> operator+ (const Ring<Key, Info>&newRing,const Ring<Key, Info>&newRing2);
    template <typename key, typename info>
    friend  Ring<key, info> operator- (const Ring<Key, Info>&subRing,const Ring<Key, Info>&subRing2);
    bool operator==(const Ring<Key,Info> &other);
    bool operator!=(const Ring<Key,Info> &other);


    bool insertAtBeg (const Key& newKey, const Info& newInfo,bool direct);
    bool insertAtEnd (const Key& newKey, const Info& newInfo,bool direct);
    bool insertAfter (const Key& newKey, const Info& newInfo, const Key& where, int occurance,bool direct);
    bool insertBefore (const Key& newKey, const Info& newInfo, const Key& where, int occurance,bool direct);

    int size()const ;
    int search (const Key& key)const; // int instead of bool number of occurance, 0 nothing
    bool remove (const Key& key, int occurance, bool direct);
    void print(bool direct);
    void print2(bool direct);
    void reverse();
    bool isEmpty() const;
    bool search2(const Key& key, int occurance);

    Iterator search3 (const Key& where, int occurance);
    bool insertAfter (const Key& newKey, const Info& newInfo, Iterator where);
    bool insertBefore (const Key& newKey, const Info& newInfo, Iterator where);

    bool insertAtBeg (Iterator what, bool direct);
    bool insertAtEnd (Iterator what, bool direct);

    Iterator begin();
    Iterator end();
    const_Iterator beginConst() const;
    const_Iterator endConst() const;

};
#endif // RING_H
