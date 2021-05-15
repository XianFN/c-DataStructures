//
// Created by xian on 10/05/2021.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <vector>
using namespace std;

template<typename Key, typename Info>
class Node {


public:
    Key key;
    Info info;
    Node *left;
    Node *right;
    int height;

    Node(Key key_,  Node *left_node = nullptr, Node *right_node = nullptr) {
        key = key_;
        info = 1;
        left = left_node;
        right = right_node;
        height = 0;
    }
    Node(Key key_, Info info_,  Node *left_node = nullptr, Node *right_node = nullptr) {
        key = key_;
        info = info_;
        left = left_node;
        right = right_node;
        height = 0;
    }

    Node(Node *left_node = nullptr, Node *right_node = nullptr) {
        key = nullptr;
        info = 1;
        left = left_node;
        right = right_node;
        height = 0;
    }
    friend bool operator==(Node const & lhs, Node const & rhs)
    {
        return lhs.info == rhs.info && lhs.key ==rhs.key
               && ((lhs.left == 0 && rhs.left == 0)
                   || (lhs.left != 0 && rhs.left != 0 && *lhs.left == *rhs.left))
               && ((lhs.right == 0 && rhs.right == 0)
                   || (lhs.right != 0 && rhs.right != 0 && *lhs.right == *rhs.right));
    }
    bool isLeaf() const { return (left == nullptr && right == nullptr); }
    bool hasRigthChild() const { return (right != nullptr); }
    bool hasLeftChild() const { return (left != nullptr ); }

};

template<typename Key, typename Info>
class Dictionary {

public:


    Dictionary();
    ~Dictionary();
    Dictionary (const Dictionary<Key, Info>&);
    Dictionary<Key, Info>& operator= (const Dictionary<Key, Info>&copy);
    Node<Key,Info>* copyHelper(const Node<Key,Info> *toCopy);

    void clear();
    bool search(const Key &where);
    int height() const;

    void inorder(void callback(const Key &where)) const;
    void inorderTraversal() const;
    bool insert(const Key &newKey);

    bool isEmpty() const;
    int leaves() const;
    int length() const;

    void preorder(void callback(const Key &where)) const;
    void preOrder2It(Node<Key,Info>* node) const;
    void preOrder2() const;
    void inorder2It(Node<Key,Info>* node) const;
    void inorder2() const;
    void printGraphIt(Node<Key,Info>* node,int ident,vector<int> indexVector)const;
    void printGraph() const;

    void preorderTraversal() const;
    bool remove(const Key &what);

    Node<Key,Info>* getRoot() const;
    Info getInfo(const Key &where);


    void preORet(Node<Key,Info> *c);

    bool operator==(const Dictionary<Key,Info> &other);
    bool operator!=(const Dictionary<Key,Info> &other);
    class NoSuchValue {
    };

private:
    Node<Key, Info> *root;
    int numNodes;

    Node<Key, Info> *balance(Node<Key, Info> *&tree);
    Node<Key, Info> *balanceFromLeft(Node<Key, Info> *&tree);
    Node<Key, Info> *balanceFromRight(Node<Key, Info> *&tree);
    void clear(Node<Key, Info> *&tree);
    Node<Key, Info> *deleteNode(Node<Key, Info> *&tree);
    int difference(const Node<Key, Info> *tree) const;
    Node<Key, Info> *find(Node<Key, Info> *tree, const Key &where) const;
    Node<Key, Info> *getmax(Node<Key, Info> *&tree);
    int height(const Node<Key, Info> *tree) const;
    void inorder(Node<Key, Info> *tree, void callback(const Key &where)) const;
    Node<Key, Info> *insertIntoAVL(Node<Key, Info> *&tree,
                                   Node<Key, Info> *&newNode,
                                   bool &isTaller);
    int leaves(const Node<Key, Info> *tree) const;
    void preorder(Node<Key, Info> *tree, void callback(const Key &where)) const;
    static void print(const Key &where);
    Node<Key, Info> *remove(Node<Key, Info> *&tree, const Key &where, bool &flag);
    Node<Key, Info> *removemax(Node<Key, Info> *&node);
    Node<Key, Info> *getNode(Node<Key, Info> *tree, const Key &where);
    Node<Key, Info> *rotateLeft(Node<Key, Info> *&tree);
    Node<Key, Info> *rotateLeftRight(Node<Key, Info> *&tree);
    Node<Key, Info> *rotateRight(Node<Key, Info> *&tree);
    Node<Key, Info> *rotateRightLeft(Node<Key, Info> *&tree);
};


#endif //DICTIONARY_H
