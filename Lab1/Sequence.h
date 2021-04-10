#ifndef Sequence_H
#define Sequence_H
#include <iostream>
#include <string>
using namespace std;

template <typename Key, typename Info>

class Sequence
{ // singly-linked list
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

    Sequence<Key, Info> &operator=(const Sequence<Key, Info> &);
    Sequence(const Sequence<Key, Info> &);

    bool insertAfter(const Key &newKey, const Info &newInfo, const Key &where, int occurance );
    bool insertBefore(const Key &newKey, const Info &newInfo, const Key &where, int occurance );
    bool insertAtEnd(const Key &newKey, const Info &newInfo);
    bool insertAtBeg(const Key &newKey, const Info &newInfo);
    bool deleteElement(const Key &delKey, int occurance);

    void prinf();
    bool getInfo(const Key &key, Info &toGet);
    bool search(const Key &key);

    Sequence<Key, Info> merge_pos(Sequence<Key, Info> &seq1, int start_pos1, int len1, Sequence<Key, Info> &seq2, int start_pos2, int len2, int count);

    Sequence<Key, Info> merge_key(Sequence<Key, Info> &seq1, const Key &start_key1, int start_occ1, int len1, Sequence<Key, Info> &seq2, const Key &start_key2, int start_occ2, int len2, int count);
};
#endif // Sequence_H
