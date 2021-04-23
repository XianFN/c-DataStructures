#ifndef RING_H
#define RING_H
#include <iostream>
#include <string>




/*
template <typename Key, typename Info>
class Ring {
    // duplicates are allowed
private:
    struct element {
        Key key;
        Info info;
        element *next;
    };
    element *any;


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

        Info& operator*();  // std::pair<Key, Info>& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        // Iterator& operator--();
        // Iterator& operator--(int);
        // Iterator operator+(int);
        //Key& getKey();
        bool getKey(Key&);
        bool setKey(const Key&);
        bool operator==(const Iterator &);
        bool operator!=(const Iterator &);
        //Iterator (const Ring<Key, Info>&);
        //Iterator associeteWith (const Ring<Key, Info>&);
        friend Ring<Key, Info>;
    };
    class const_Iterator {
        const element* ptr;
        Ring<Key, Info>* owner;

        const_Iterator(element* xtr,Ring<Key, Info>*otr):ptr(xtr){
            owner = otr;
        }
    public:
        const_Iterator (Ring<Key, Info>*otr=nullptr): ptr(nullptr){
            owner = otr;
        }
        const Info& operator*();  // std::pair<Key, Info>& operator*();
        const_Iterator & operator++();
        const_Iterator operator++(int);

        //const Key& getKey();
        const Key& getKey();

        bool operator==(const Iterator &);
        bool operator!=(const Iterator &);
        //Iterator (const Ring<Key, Info>&);
        //Iterator associeteWith (const Ring<Key, Info>&);
        friend Ring<Key, Info>;
    };

Ring();
~Ring();
Ring (const Ring<Key, Info>&);
Ring<Key, Info>& operator= (const Ring<Key, Info>&);
Iterator search (const Key& where, int occurance=1);
bool insertAfter (const Key& newKey, const Info& newInfo, const Key& where, int occurance=1);
bool insertAfter (const Key& newKey, const Info& newInfo, Iterator where);
int search (const Key& key); // int instead of bool
bool remove (const Key& key, int occurance=1);
bool search2(const Key& key, int occurance=1);
void print();
Iterator begin();
Iterator end();
};
*/





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
    bool search (element& curr, element& prev, const Key& key, int occurance=1);

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
        //constructores?
        //Iterator();
        //~Iterator();

        Info& operator*();  // std::pair<Key, Info>& operator*();
        Iterator& operator++();
        Iterator operator++(int);
         Iterator& operator--();
         Iterator& operator--(int);
         Iterator operator+(int);
        Key& getKey();
        bool getKey(Key&);
        bool setKey(const Key&);
        bool operator==(const Iterator &other);
        bool operator!=(const Iterator &other);
        //Iterator (const Ring<Key, Info>&);
        //Iterator associeteWith (const Ring<Key, Info>&);
        friend Ring<Key, Info>;
    };
    class const_Iterator {
        const element* ptr;
        Ring<Key, Info>* owner;

        const_Iterator(element* xtr,Ring<Key, Info>*otr):ptr(xtr){
            owner = otr;
        }
    public:
        const_Iterator (Ring<Key, Info>*otr=nullptr): ptr(nullptr){
            owner = otr;
        }
        const Info& operator*();  // std::pair<Key, Info>& operator*();
        const_Iterator & operator++();
        const_Iterator operator++(int);

        //const Key& getKey();
        const Key& getKey();

        bool operator==(const Iterator &);
        bool operator!=(const Iterator &);
        //Iterator (const Ring<Key, Info>&);
        //Iterator associeteWith (const Ring<Key, Info>&);
        friend Ring<Key, Info>;
    };
    Ring();
    ~Ring();
    Ring (const Ring<Key, Info>&);
    Ring<Key, Info>& operator= (const Ring<Key, Info>&copy);

    Ring<Key, Info>& operator++ ();
    Ring<Key, Info>& operator+ (const Ring<Key, Info>&newIt);
    Ring<Key, Info>& operator+= (const Ring<Key, Info>&newIt);
    Ring<Key, Info>& operator-- ();
    Ring<Key, Info>& operator- (const Ring<Key, Info>&subIt);
    Ring<Key, Info>& operator-= (const Ring<Key, Info>&subIt);



    bool insertAtBeg (const Key& newKey, const Info& newInfo,bool direct);
    bool insertAtEnd (const Key& newKey, const Info& newInfo,bool direct);


    bool insertAfter (const Key& newKey, const Info& newInfo, const Key& where, int occurance,bool direct);
    bool insertBefore (const Key& newKey, const Info& newInfo, const Key& where, int occurance,bool direct);

    int search (const Key& key); // int instead of bool number of occurance, 0 nothing
    bool remove (const Key& key, int occurance, bool direct);
    void print(bool direct);
     void print2(bool direct);
    void reverse();

    bool search2(const Key& key, int occurance);


    Iterator search3 (const Key& where, int occurance=1);
    bool insertAfter (const Key& newKey, const Info& newInfo, Iterator where);
    Iterator begin();
    Iterator end();
    bool AssertEquals(std::string wantedOutput);

};
#endif // RING_H





