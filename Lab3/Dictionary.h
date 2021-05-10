//
// Created by xian on 10/05/2021.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>

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
        info = 0;
        left = left_node;
        right = right_node;
        height = 0;
    }

    Node(Node *left_node = nullptr, Node *right_node = nullptr) {
        key = nullptr;
        info = nullptr;
        left = left_node;
        right = right_node;
        height = 0;
    }

    bool isLeaf() const { return (left == nullptr && right == nullptr); }

};

template<typename Key, typename Info>
class Dictionary {

public:

    /** Constructor */
    Dictionary();

    /** Destructor */
    ~Dictionary();

    /** Clears the AVL tree of all items
    @post: the tree will be completely empty */
    void clear();

    /** Determines if a value is in the AVL tree
    @param: value a reference to the value to search for
    @return: true if the the value is found, false otherwise */
    bool search(const Key &where);

    /** Returns the height of the tree
    @return: the height of the tree */
    int height() const;

    /** Traverses a subtree in inorder and processes the nodes using the given
        callback
    @pre: the subtree should not be empty
    @param: callback the callback that processes the node */
    void inorder(void callback(const Key &where)) const;

    /** Traverses the AVL tree and prints the items in inorder
    @post: the value of the items in the AVL tree will printed to the terminal
        in inorder */
    void inorderTraversal() const;

    /** Inserts an item into the ALV tree
    @param: newItem the item to be inserted
    @return: true if the item was inserted, false otherwise
    @post: the item will be inserted into the AVL tree */
    bool insert(const Key &newKey);

    /** Tests if the tree is empty
    @return: true if the tree is empty, false otherwise */
    bool isEmpty() const;

    /** Returns the number of leaves in the AVL tree
    @return: the number of leaves in the AVL tree */
    int leaves() const;

    /** Returns the length (number of nodes) in the AVL tree
    @return the length (number of nodes) in the AVL tree */
    int length() const;

    /** Traverses a subtree in preorder and processes the nodes using the given
        callback
    @pre: the subtree should not be empty
    @param: callback the callback that processes the node */
    void preorder(void callback(const Key &where)) const;

    /** Traverses the AVL tree and prints the items in preorder
    @post: the value of the items in the AVL tree will printed to the terminal
        in inorder */
    void preorderTraversal() const;

    /** Removes an item from the AVL tree
    @param: removeItem the item to be removed
    @return: true if the item was found and removed, false otherwise
    @post: the item will no longer be in the AVL tree  */
    bool remove(const Key &what);

    /** Retrieves a value from the tree
    @pre: the value must be in the tree, otherwise a NoSuchValue exception will
        be thrown
    @param: value the value to search for
    @return: returns the value from the tree if it is found, otherwise a
        NoSuchValue exception will be thrown */


    Info getInfo(const Key &where);

    /** Exception class for when a value is not in the AVL tree */
    class NoSuchValue {
    };

private:
    Node<Key, Info> *root;
    int numNodes;

    /** Balances the AVL tree, if necessary. If a node's balance factor is
        greater than 1, it is unbalanced and will balanced. Otherwise, nothing
        will change
    @pre: the subtree is not empty
    @param: tree the subtree to balance
    @return: pointer to the balanced tree
    @post: the subtree will be balanced */
    Node<Key, Info> *balance(Node<Key, Info> *&tree);

    /** Balances a subtree from the left
    @pre: the subtree is not empty
    @param: tree the subtree to balance
    @return: pointer to the balanced tree
    @post: the subtree will be balanced */
    Node<Key, Info> *balanceFromLeft(Node<Key, Info> *&tree);

    /** Balances a subtree from the right
    @pre: the subtree is not empty
    @param: tree the subtree to balance
    @return: pointer to the balanced tree
    @post: the subtree will be balanced */
    Node<Key, Info> *balanceFromRight(Node<Key, Info> *&tree);

    /** Clears a subtree of all its contents
    @param: tree a pointer to the subtree to clear
    @post: the subtree content's will be removed */
    void clear(Node<Key, Info> *&tree);

    /** Deletes a node from a subtree
    @param: node a reference to a pointer to the node to be deleted
    @return: pointer to the node that takes the place of the deleted node
    @post: the node will be deleted and, if possible, replaced with a new
        node */
    Node<Key, Info> *deleteNode(Node<Key, Info> *&tree);

    /** Calculates the difference between the heights of the left and right
        subtrees rooted at the given node
    @pre: the given subtree is not empty
    @param: tree pointer to the subtree
    @return: the height of the subtree */
    int difference(const Node<Key, Info> *tree) const;

    /** Finds a value in a subtree
    @param: tree the subtree to search
    @param: value the value to find in the subtree
    @return: pointer to the location of the node in the subtree that holds
        value */
    Node<Key, Info> *find(Node<Key, Info> *tree, const Key &where) const;

    /** Finds the node with the maximum value in a subtree
    @param: tree a reference to a pointer to the subtree to search
    @return: pointer to the node with the maximum value in a subtree */
    Node<Key, Info> *getmax(Node<Key, Info> *&tree);

    /** Calculates the height of the subtree rooted at the given node
    @param: tree pointer to the subtree
    @return: the height of the subtree */
    int height(const Node<Key, Info> *tree) const;

    /** Traverses a subtree in inorder and processes the value using the given
        callback function
    @pre: the subtree should not be empty
    @param: tree the subtree to be traversed
    @param: callback the function used to process the value in the node */
    void inorder(Node<Key, Info> *tree, void callback(const Key &where)) const;

    /** Inserts a new node into a subtree
    @param: tree the subtree that the new node will be inserted into
    @param: newNode the node to be inserted into the subtree
    @param: isTaller a flag to indicate if subtree is taller  */
    Node<Key, Info> *insertIntoAVL(Node<Key, Info> *&tree,
                                   Node<Key, Info> *&newNode,
                                   bool &isTaller);

    /** Counts the number of leaves in a subtree
    @param: tree pointer to the subtree
    @return: the number of leaves in the subtree */
    int leaves(const Node<Key, Info> *tree) const;

    /** Traverses a subtree in preorder
    @pre: the subtree should not be empty
    @param: tree the subtree to be traversed
    @param: callback the function used to process the value in the node */
    void preorder(Node<Key, Info> *tree, void callback(const Key &where)) const;

    /** Prints the value to the terminal
    @param: value reference to the value to be printed
    @post: the terminal will have the value printed to it */
    static void print(const Key &where);

    /** Removes a value from a subtree
    @param: tree the subtree to remove the value from
    @param: valuethe value to remove
    @param: flag a flag to signal whether or not the value was found and removed
        or not
    @post: if found, the value will be removed from the subtree. the structure
        or shape of the tree may change as well
           flag will be set to true if the value is found and removed, false
           otherwise*/
    Node<Key, Info> *remove(Node<Key, Info> *&tree, const Key &where, bool &flag);

    /** Removes (not delete!) the node with the maximum value in a subtree
        pointer to it
    @param: tree a reference to a pointer to the subtree to search
    @return: a pointer to the node with the maximum value in the subtree
    @post: the node with the maximum value in the subtree will be removed from
        the subtree but not deleted */
    Node<Key, Info> *removemax(Node<Key, Info> *&node);

    /** Retrieves an item from a subtree
    @param: tree the subtree to search
    @param: value reference to the value to search for */
    Node<Key, Info> *getNode(Node<Key, Info> *tree, const Key &where);

    /** Performs a left rotation on a subtree
    @pre: the subtree should not be empty
    @param: tree the subtree to be left rotated
    @return: pointer to the left rotated subtree
    @post: the subtree will be left rotated */
    Node<Key, Info> *rotateLeft(Node<Key, Info> *&tree);

    /** Performs a left-right rotation on a subtree
    @pre: the subtree should not be empty
    @param: tree the subtree to be left-right rotated
    @return: pointer to the left-right rotated subtree
    @post: the subtree will be left-right rotated */
    Node<Key, Info> *rotateLeftRight(Node<Key, Info> *&tree);

    /** Performs a right rotation on a subtree
    @pre: the subtree should not be empty
    @param: tree the subtree to be right rotated
    @return: pointer to the right rotated subtree
    @post: the subtree will be right rotated */
    Node<Key, Info> *rotateRight(Node<Key, Info> *&tree);

    /** Performs a right-left rotation on a subtree
    @pre: the subtree should not be empty
    @param: tree the subtree to be right-left rotated
    @return: pointer to the right-left rotated subtree
    @post: the subtree will be right-left rotated */
    Node<Key, Info> *rotateRightLeft(Node<Key, Info> *&tree);
};


#endif //DICTIONARY_H
