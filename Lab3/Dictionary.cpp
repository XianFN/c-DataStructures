//
// Created by xian on 10/05/2021.
//
//
// Created by xian on 10/05/2021.
//
#include <iostream>
#include "Dictionary.h"
#include <vector>
using namespace std;




// Constructor
template<typename Key, typename Info>
Dictionary<Key,Info>::Dictionary()
{
    root = nullptr;
    numNodes = 0;
}


// Destructor
template<typename Key, typename Info>
Dictionary<Key,Info>::~Dictionary()
{
    clear();
}

// Clears the AVL tree of all items
template<typename Key, typename Info>
void Dictionary<Key,Info>::clear()
{
    clear(root);
    numNodes = 0;
}

// Determines if a value is in the AVL tree
template<typename Key, typename Info>
bool Dictionary<Key,Info>::search(const Key& value)
{
    return nullptr != getNode(root, value);
}

// Returns the height of the tree
template<typename Key, typename Info>
int Dictionary<Key,Info>::height() const
{
    return height(root);
}

// Traverses a subtree in inorder and processes the nodes using the given
// callback
template<typename Key, typename Info>
void Dictionary<Key,Info>::inorder(void callback(const Key& where)) const
{
    inorder(root, callback);
}

// Traverses the AVL tree and prints the items in it in inorder
template<typename Key, typename Info>
void Dictionary<Key,Info>::inorderTraversal() const
{
    inorder(root, print);
}

// Inserts an item into the ALV tree
template<typename Key, typename Info>
bool Dictionary<Key,Info>::insert(const Key& newKey)
{
    bool isTaller = false;
    Node<Key,Info>* newNode = new Node<Key,Info>(newKey);

    root = insertIntoAVL(root, newNode, isTaller);

    return true;
}

// Tests if the tree is empty
template<typename Key, typename Info>
bool Dictionary<Key,Info>::isEmpty() const
{
    return root == nullptr;
}

// Returns the number of leaves in the AVL tree
template<typename Key, typename Info>
int Dictionary<Key,Info>::leaves() const
{
    return leaves(root);
}

// Returns the length (number of nodes) in the AVL tree
template<typename Key, typename Info>
int Dictionary<Key,Info>::length() const
{
    return numNodes;
}

// Traverses a subtree in preorder and processes the nodes using the given
// callback
template<typename Key, typename Info>
void Dictionary<Key,Info>::preorder(void callback(const Key& where)) const
{
    preorder(root, callback);
}

// Traverses the AVL tree and prints the items in preorder
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
template<typename Key, typename Info>
void Dictionary<Key,Info>::printGraphHorizontal() const
{

    if (root != NULL)
    {
        vector<int> indexVector(this->length(), 0);;
        cout<<endl;
        printGraphHorizontalIt(root,0,indexVector,root->height,this->length()/2,this->length()/2);
    }
}
template<typename Key, typename Info>
void Dictionary<Key,Info>::printGraphHorizontalIt(Node<Key,Info>* node,int ident, vector<int> indexVector,int currHeigth,int horizontalIndex,int actualSpaces) const{

    /*
    if(ident > 0)
    {
        if (node->height==currHeigth){
            for(int i = 0; i < ident - 1; ++i) {

            }

        }else{
            cout<<endl;
        }


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

     */
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
    cout<<"endl";
    if (root){
        return root;
    }else{
        return new Node<Key,Info>();
    }

}
// Retrieves a info from the tree
template<typename Key, typename Info>
Info Dictionary<Key,Info>::getInfo(const Key& value)
{
    // Attempt to find the value. If it can't be found (node is nullptr)
    // then throw an error. Otherwise, return the value
    Node<Key,Info>* node = getNode(root, value);
    if (node == nullptr)
    {
        // Enforce the precondition that the value should be in the tree
        throw NoSuchValue();
    }

    return node->info;
}

// Private methods
// Balances the AVL tree, if necessary. If a node's balance factor is greater
// than 1, it is unbalanced and will balanced. Otherwise, nothing will change
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

// Balances a subtree from the right
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

// Clears a subtree of all its contents
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

// Deletes a node from a subtree
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
        //TODO arregar delete, que se a infor e mais de 0 so reste un
        toDelete = getmax(node->left);
        node->key = toDelete->key;
        node->left = removemax(node->left);
    }

    delete toDelete;
    toDelete = nullptr;

    return node;
}

// Calculates the difference between the heights of the left and right subtrees
// rooted at the given node
template<typename Key, typename Info>
int Dictionary<Key,Info>::difference(const Node<Key,Info>* tree) const
{
    return height(tree->left) - height(tree->right);
}

// Finds a value in a subtree
template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::find(Node<Key,Info>* tree, const Key& value) const
{
    return nullptr;
}

// Finds the node with the maximum value in a subtree
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

// Calculates the height of the subtree rooted at the given node
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

// Traverses a subtree in inorder and processes the value using the given
// callback function
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

// Inserts a new node into a subtree
template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::insertIntoAVL(Node<Key,Info>*& tree,
                                                    Node<Key,Info>*& newNode,
                                                    bool& isTaller)
{
    // use convention that values less than or equal to the value
    // in a node belong in the left subtree
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

// Counts the number of leaves in a subtree
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

// Traverses a subtree in preorder and processes the value using the given
// callback function
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

// Prints the value to the terminal
template<typename Key, typename Info>
void Dictionary<Key,Info>::print(const Key& where)
{
    std::cout << where << " ";
}

// Removes a value from a subtree
template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::remove(Node<Key,Info>*& tree, const Key& value, bool& flag)
{
    // didn't find the value
    if (tree == nullptr)
    {
        flag = false;
        return tree;
    }

    // keep traversing the subtree until we find the correct node
    if (tree->key < value) // go to the right subtree
    {
        tree->right = remove(tree->right, value, flag);
        tree = balance(tree);
    }
    else if (tree->key > value) // go to the left subtree
    {
        tree->left = remove(tree->left, value, flag);
        tree = balance(tree);
    }
    else // found the value, delete it
    {
        flag = true;
        numNodes--;
        tree = deleteNode(tree);
    }

    return tree;
}

// Removes (not delete!) the node with the maximum value in a subtree pointer
// to it
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

// Retrieves an item from a subtree
template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::getNode(Node<Key,Info>* tree, const Key& where)
{
    // The value is not in the tree
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

// Performs a left rotation on a subtree
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

// Performs a left-right rotation on a subtree
template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::rotateLeftRight(Node<Key,Info>*& tree)
{
    // From the diagram in the lecture notes, slide 29
    Node<Key,Info>* s = tree->left;
    tree->left = rotateLeft(s);
    tree = rotateRight(tree);

    return tree;
}

// Performs a right rotation on a subtree
template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::rotateRight(Node<Key,Info>*& tree)
{
    if (tree->left != nullptr)
    {
        // From the diagram in the lecture notes, slide 22
        Node<Key,Info>* s = tree->left;
        Node<Key,Info>* b = s->right;

        s->right = tree;
        tree->left = b;
        return s;
    }

    return tree;
}

// Performs a right-left rotation on a subtree
template<typename Key, typename Info>
Node<Key,Info>* Dictionary<Key,Info>::rotateRightLeft(Node<Key,Info>*& tree)
{
    // From the diagram in the lecture notes, slide 27
    Node<Key,Info>* s = tree->right;
    tree->right = rotateRight(s);
    tree = rotateLeft(tree);
    return tree;
}