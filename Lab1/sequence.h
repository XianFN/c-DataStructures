#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <string>
using namespace std;

template <typename Key, typename Info>


class Sequence
{
private:
    struct element
    {

            Key key;
            Info info;
            element *next;


    };
    element *head;
public:


    Sequence();
    ~Sequence();
    Sequence(const Sequence<Key, Info>& copy);


    Sequence<Key, Info> &operator=(const Sequence<Key, Info> & move);

    bool insertAfter(const Key &newKey, const Info &newInfo, const Key &where, int occurance );
    bool insertBefore(const Key &newKey, const Info &newInfo, const Key &where, int occurance );
    bool insertAtEnd(const Key &newKey, const Info &newInfo);
    bool insertAtBeg(const Key &newKey, const Info &newInfo);
    bool isEmpty();
    bool itsNodeEmpty(int index);
    Key getKey(int index);
    Info getInfo(int index);
    bool deleteElement(const Key &delKey, int occurance);


    void prinf();
    bool search(const Key &what, int occurance);
    bool AssertEquals(string wantedOutput);



};

#endif // SEQUENCE_H
