
//
// Created by xian on 10/05/2021.
//
#include <iostream>
#include "Dictionary.h"
#include <vector>
using namespace std;


template<typename Key, typename Info>
Dictionary<Key,Info>::Dictionary()
{
    root = nullptr;
    numNodes = 0;
}



template<typename Key, typename Info>
Dictionary<Key,Info>::~Dictionary()
{
    clear();
}


template<typename Key, typename Info>
void Dictionary<Key,Info>::clear()
{
    clear(root);
    numNodes = 0;
}


template<typename Key, typename Info>
bool Dictionary<Key,Info>::search(const Key& value)
{
    return nullptr != getNode(root, value);
}


template<typename Key, typename Info>
int Dictionary<Key,Info>::height() const
{
    return height(root);
}

template<typename Key, typename Info>
void Dictionary<Key,Info>::inorder2() const
{

    if (root != NULL)
    {
        cout<<endl;
        inorder2It(root);
    }
}
template<typename Key, typename Info>
void Dictionary<Key,Info>::inorder2It(Node<Key,Info>* node) const
{
    if (node != NULL)
    {
        cout <<"["<< node->key << ","<<node->info << "] ";
        inorder2It(node->right);
        inorder2It(node->left);

    }
}

template<typename Key, typename Info>
void Dictionary<Key,Info>::inorder(void callback(const Key& where)) const
{
    inorder(root, callback);
}


template<typename Key, typename Info>
void Dictionary<Key,Info>::inorderTraversal() const
{
    inorder(root, print);
}


template<typename Key, typename Info>
bool Dictionary<Key,Info>::insert(const Key& newKey)
{
    bool isTaller = false;
    Node<Key,Info>* newNode = new Node<Key,Info>(newKey);

    root = insertIntoAVL(root, newNode, isTaller);

    return true;
}


template<typename Key, typename Info>
bool Dictionary<Key,Info>::isEmpty() const
{
    return root == nullptr;
}


template<typename Key, typename Info>
int Dictionary<Key,Info>::leaves() const
{
    return leaves(root);
}


template<typename Key, typename Info>
int Dictionary<Key,Info>::length() const
{
    return numNodes;
}


template<typename Key, typename Info>
void Dictionary<Key,Info>::preorder(void callback(const Key& where)) const
{
    preorder(root, callback);
}

template<typename Key, typename Info>
void Dictionary<Key,Info>::preorderTraversal() const
{
    preorder(root, print);
}
template<typename Key, typename Info>
void Dictionary<Key,Info>::preOrder2() const
{

    if (root != NULL)
    {
        cout<<endl;
        preOrder2It(root);
    }
}
template<typename Key, typename Info>
void Dictionary<Key,Info>::preOrder2It(Node<Key,Info>* node) const
{
    if (node != NULL)
    {
        cout <<"["<< node->key << ","<<node->info << "] ";
        preOrder2It(node->left);
        preOrder2It(node->right);
    }
}
template<typename Key, typename Info>
void Dictionary<Key,Info>::printGraph() const
{

    if (root != NULL)
    {
        vector<int> indexVector(this->length(), 0);;
        cout<<endl;
        printGraphIt(root,0,indexVector);
    }
}
template<typename Key, typename Info>
 void Dictionary<Key,Info>::printGraphIt(Node<Key,Info>* node,int ident, vector<int> indexVector) const{

    if(ident > 0)
    {
        for(int i = 0; i < ident - 1; ++i)
        {
            printf(indexVector[i] ? "│   " : "    ");
        }
        printf(indexVector[ident-1] ? "├── " : "└── ");
    }

    if(! node)
    {
        printf("(null)\n");
        return;
    }

    cout<<node->key<<"("<<node->info<<")"<<endl;
    if(!node->left && !node->right)
    {
        return;
    }

    indexVector[ident] = 1;
    printGraphIt(node->left, ident + 1,indexVector);
    indexVector[ident] = 0;
    printGraphIt(node->right, ident + 1,indexVector);

}
// Removes an item from the AVL tree
template<typename Key, typename Info>
bool Dictionary<Key,Info>::remove(const Key& what)
{
    bool isRemoved = false;
    root =  remove(root, what, isRemoved);
    return isRemoved;
}


template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::getRoot() const{
    if (root){
        return root;
    }else{
        return new Node<Key,Info>();
    }

}

template<typename Key, typename Info>
Info Dictionary<Key,Info>::getInfo(const Key& value)
{

    Node<Key,Info>* node = getNode(root, value);
    if (node == nullptr)
    {

        throw NoSuchValue();
    }

    return node->info;
}


template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::balance(Node<Key,Info>*& tree)
{
    int balanceFactor = difference(tree);

    // three cases:
    // 1. left subtree needs balancing (balance factor > 1)
    // 2. right subtree needs balancing (balance factor < -1)
    // 3. subtrees are balanced (-1 <= balance factor <= 1)
    if (balanceFactor > 1) // left subtree needs balancing
    {
        tree = balanceFromLeft(tree);
        return tree;
    }
    else if (balanceFactor < -1) // right subtree needs balancing
    {
        tree = balanceFromRight(tree);
        return tree;
    }
    else // subtrees are balanced
    {
        return tree;
    }
}

// Balances a subtree from the left
template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::balanceFromLeft(Node<Key,Info>*& tree)
{
    // two cases:
    // 1. one rotation is needed
    // 2. two rotations are needed
    if (difference(tree->left) > 1)
    {
        tree = rotateRight(tree);
        return tree;
    }
    else
    {
        tree = rotateLeftRight(tree);
        return tree;
    }
}


template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::balanceFromRight(Node<Key,Info>*& tree)
{
    // two cases:
    // 1. one rotation is needed
    // 2. two rotations are needed
    if (difference(tree->right) < 0)
    {
        tree = rotateLeft(tree);
        return tree;
    }
    else
    {
        tree = rotateRightLeft(tree);
        return tree;
    }
}


template<typename Key, typename Info>
void Dictionary<Key,Info>::clear(Node<Key,Info>*& tree)
{
    if (tree != nullptr)
    {
        if (tree->left)
        {
            clear(tree->left);
        }
        if (tree->right)
        {
            clear(tree->right);
        }

        delete tree;
        tree = nullptr;
    }
}


template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::deleteNode(Node<Key,Info>*& node)
{
    // three cases
    // 1. no children
    // 2. one child (left or right)
    // 3. two children
    Node<Key,Info>* toDelete = node;
    if (node->left == nullptr)
    {
        node = node->right;
    }
    else if (node->right == nullptr)
    {
        node = node->left;
    }
    else
    {
        // to delete a node with two children
        // 1. find the logical predecessor (largest node of left subtree)
        // 2. replace node that we're deleting with logical predecessor
        // 3. delete the node
        toDelete = getmax(node->left);
        node->key = toDelete->key;
        node->left = removemax(node->left);
    }

    delete toDelete;
    toDelete = nullptr;

    return node;
}

template<typename Key, typename Info>
int Dictionary<Key,Info>::difference(const Node<Key,Info>* tree) const
{
    return height(tree->left) - height(tree->right);
}

template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::find(Node<Key,Info>* tree, const Key& value) const
{
    return nullptr;
}

template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::getmax(Node<Key,Info>*& tree)
{
    // traverse down the right subtree until the right child
    // is null, then we've arrived at the max node
    if (tree->right == nullptr)
    {
        return tree;
    }
    else
    {
        return getmax(tree->right);
    }
}


template<typename Key, typename Info>
int Dictionary<Key,Info>::height(const Node<Key,Info>* tree) const
{
    // Don't count null nodes
    if (tree == nullptr)
    {
        return 0;
    }

    // Recursively determine the height only using the larger
    // of the two subtrees (left vs right)
    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


template<typename Key, typename Info>
void Dictionary<Key,Info>::inorder(Node<Key,Info>* tree,
                                   void callback(const Key &where)) const
{
    if (tree != nullptr)
    {
        inorder(tree->left, callback);
        (*callback)(tree->key);
        inorder(tree->right, callback);
    }
}


template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::insertIntoAVL(Node<Key,Info>*& tree,
                                                    Node<Key,Info>*& newNode,
                                                    bool& isTaller)
{

    if (tree == nullptr)
    {
        tree = newNode;
        numNodes++;
    }
    else if(tree->key == newNode->key){
        tree->info++;
    }
            else if (tree->key > newNode->key)
    {
        tree->left = insertIntoAVL(tree->left, newNode, isTaller);
        tree = balance(tree);
    }
    else
    {
        tree->right = insertIntoAVL(tree->right, newNode, isTaller);
        tree = balance(tree);
    }

    return tree;
}

template<typename Key, typename Info>
int Dictionary<Key,Info>::leaves(const Node<Key,Info>* tree) const
{
    if (tree == nullptr)
    {
        return 0;
    }

    if (tree->isLeaf())
    {
        return 1;
    }
    else
    {
        return leaves(tree->left) + leaves(tree->right);
    }
}

template<typename Key, typename Info>
void Dictionary<Key,Info>::preorder(Node<Key,Info>* tree,
                                    void callback(const Key& value)) const
{
    if (tree != nullptr)
    {
        (*callback)(tree->key);
        preorder(tree->left, callback);
        preorder(tree->right, callback);
    }
}

template<typename Key, typename Info>
void Dictionary<Key,Info>::print(const Key& where)
{
    std::cout << where << " ";
}

template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::remove(Node<Key,Info>*& tree, const Key& value, bool& flag)
{

    if (tree == nullptr)
    {
        flag = false;
        return tree;
    }


    if (tree->key < value)
    {
        tree->right = remove(tree->right, value, flag);
        tree = balance(tree);
    }
    else if (tree->key > value)
    {
        tree->left = remove(tree->left, value, flag);
        tree = balance(tree);
    }
    else
    {
        flag = true;
        numNodes--;
        tree = deleteNode(tree);
    }

    return tree;
}


template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::removemax(Node<Key,Info>*& tree)
{
    if (tree->right == nullptr)
    {
        return tree->left;
    }
    else
    {
        tree->right = removemax(tree->right);
        return tree;
    }
}


template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::getNode(Node<Key,Info>* tree, const Key& where)
{

    if (tree == nullptr)
    {
        return nullptr;
    }

    // three cases
    // 1. go right
    // 2. go left
    // 3. found
    if (tree->key < where)
    {
        return getNode(tree->right, where);
    }
    else if (tree->key > where)
    {
        return getNode(tree->left, where);
    }
    else
    {
        return tree;
    }
}

template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::rotateLeft(Node<Key,Info>*& tree)
{
    if (tree->right != nullptr)
    {
        // From the diagram in the lecture notes, slide 25
        Node<Key,Info>* s = tree->right;
        Node<Key,Info>* b = s->left;

        s->left = tree;
        tree->right = b;

        return s;
    }

    return tree;
}

template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::rotateLeftRight(Node<Key,Info>*& tree)
{

    Node<Key,Info>* s = tree->left;
    tree->left = rotateLeft(s);
    tree = rotateRight(tree);

    return tree;
}

template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::rotateRight(Node<Key,Info>*& tree)
{
    if (tree->left != nullptr)
    {

        Node<Key,Info>* s = tree->left;
        Node<Key,Info>* b = s->right;

        s->right = tree;
        tree->left = b;
        return s;
    }

    return tree;
}

template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::rotateRightLeft(Node<Key,Info>*& tree)
{
    Node<Key,Info>* s = tree->right;
    tree->right = rotateRight(s);
    tree = rotateLeft(tree);
    return tree;
}

template<typename Key, typename Info>
Dictionary<Key,Info>::Dictionary (const Dictionary<Key, Info>&that){

    root = copyHelper(that.root);

}

template<typename Key, typename Info>
Dictionary<Key,Info>& Dictionary<Key,Info>::operator=(const Dictionary<Key,Info>& that)
{
    //COPY
    if(this != &that)
    {
        this->clear();
        Node<Key,Info> *c = that.root;
        preORet(c);
    }
    return *this;
}

template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::copyHelper(const Node<Key,Info> *toCopy){
    if (toCopy == NULL)
        return NULL;
    Node<Key,Info> *copyNode = new Node<Key,Info>(toCopy->key,toCopy->info);
    copyNode->left = copyHelper(toCopy->left);
    copyNode->right = copyHelper(toCopy->right);
    return copyNode;
}
template<typename Key, typename Info>
void Dictionary<Key,Info>::preORet(Node<Key,Info> *c)
{
    this->insert(c->key);

    if(c->left != nullptr)
        preORet(c->left);
    else if(c->right != nullptr)
        preORet(c->right);
}
template<typename Key, typename Info>
bool Dictionary<Key,Info>::operator==(const Dictionary<Key,Info> &other){

        return (root == 0 && other.root == 0)
               || (root != 0 && other.root != 0 && *root == *other.root);

}

template<typename Key, typename Info>
bool Dictionary<Key,Info>::operator!=(const Dictionary<Key,Info> &other){
    return !(*this==other);
}


