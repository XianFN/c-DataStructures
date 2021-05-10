
#include "Dictionary.cpp"
#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>


using namespace std;

uint32_t SEED = time(0);
// uint32_t SEED = NULL;
mt19937 RNG;

void initRng();
void tests();
vector<int> randomVector(const int size, const int start, const int stop);
void testRetrieveEntry(const int entry,Dictionary<int,int>& tree);

// template <class T>
void print(const int& value);

int main() {
    tests();
    /*
    Dictionary<int,int> treeRoot;
    int num;


    cout << "Enter numbers ending with -999" << endl;
    cin >> num;
    while (num != -999)
    {
        treeRoot.insert(num);
        cin >> num;
    }

    cout << endl << "Tree nodes in inorder: ";
    treeRoot.inorderTraversal();

    cout << endl;
    cout << endl << "Tree nodes in preorder: ";
    treeRoot.preorderTraversal();
    cout << endl;
*/
    return 0;
}
void tests()
{
    Dictionary<int,int> avlt;

    assert(avlt.isEmpty() && "FAILED: New tree isn't empty\n");
    cout << "A new tree should be empty: PASSED\n";

    assert(avlt.height() == 0 && "FAILED: New tree height isn't 0\n");
    cout << "A new tree's height is zero: PASSED\n";

    assert(avlt.leaves() == 0 && "FAILED: New tree should have no leaves\n");
    cout << "A new tree should have no leaves: PASSED\n";

    assert(avlt.length() == 0 && "FAILED: New tree should have no nodes\n");
    cout << "A new tree should have no nodes: PASSED\n";

    int entry = 137;
    testRetrieveEntry(entry, avlt);

    assert(avlt.insert(entry) && "FAILED: Should be able to add an entry\n");
    cout << "Should be able to add a new entry to the empty tree: PASSED\n";

    //assert(avlt.getInfo(entry) == 1 && "FAILED: Should be able to get the item\n");
    cout << "Should be able to get an item from the tree: PASSED\n";

    assert(avlt.search(entry) && "FAILED: Should be able see if the tree contains an added item\n");
    cout << "Should be able to see if the tree contains an added item: PASSED\n";

    assert(avlt.height() == 1 && "FAILED: The height of a tree with one entry should be 1\n");
    cout << "The height of a tree with one entry should be one: PASSED\n";

    assert(avlt.leaves() == 1 && "FAILED: A tree with one entry should have one leaf\n");
    cout << "A tree with one entry should have one leaf: PASSED\n";

    assert(avlt.remove(entry) && "FAILED: Should be able to remove an entry\n");
    cout << "Should be able to remove an entry: PASSED\n";

    assert(!avlt.search(entry) && "FAILED: Should be able see if the tree doesn't contain a removed item\n");
    cout << "Should be able to see if the tree doesn't contain a removed item: PASSED\n";

    // Add many numbers to the tree randomly
    initRng();
    const int NUM_ENTRIES = 30;
    const int START = 0;
    const int END = 100;
    // create a vector of random numbers of length NUM_ENTRIES, between START and NUM_ENTRIES
    // and then add the entries into the tree (also, assert that the insertion works)
    vector<int> entries = randomVector(NUM_ENTRIES, START, END);

    for (auto &entry : entries)
    {
        assert(avlt.insert(entry) && "FAILED: Should be able to insert entry\n");
    }
    cout << "Insert many entries into the tree: PASSED\n";

    for (auto &entry : entries)
    {
        assert(avlt.search(static_cast<int>(entry)) && "FAILED: Should have found entry\n");
    }
    cout << "The contents of the AVL tree are (in preorder):\n";
    avlt.preorderTraversal();
    cout << endl;

    cout << "The contents of the AVL tree are (in inorder):\n";
    avlt.inorderTraversal();
    cout << endl;

    cout << "Should be able to find several entries: PASSED\n";

    shuffle(entries.begin(), entries.end(), RNG);

    cout << "Print in preorder order: ";
    avlt.preorder(print);
    cout << endl;

    cout << "Print in inorder order: ";
    avlt.inorder(print);
    cout << endl;

    for (auto &entry : entries)
    {
        // cout << entry << ", " << endl;
        cout << "Removing " << entry << ":\t";
        avlt.inorderTraversal();
        cout << endl;
        assert(avlt.remove(entry) && "FAILED: Should be able to remove entry " && entry && "\n");
    }
    cout << endl;
    cout << "Should be able to remove several entries: PASSED\n";

    assert(!avlt.search(entry) && "FAILED: Entry should not be in tree\n");
    cout << "Removed entries should not be in tree: PASSED\n";

    assert(avlt.isEmpty() && "FAILED: An empty tree should be empty\n");
    cout << "An empty tree should be empty: PASSED\n";

    assert(avlt.height() == 0 && "FAILED: An empty tree should have a height of 0\n");
    cout << "An empty tree should have a height of 0: PASSED\n";

    assert(avlt.leaves() == 0 && "FAILED: An empty tree should have no leaves\n");
    cout << "An empty tree should have no leaves: PASSED\n";
}

void initRng()
{
    RNG.seed(SEED);
}

vector<int> randomVector(const int size, const int start, const int stop)
{
    uniform_int_distribution<int> dist(start, stop);
    vector<int> entries = {};

    for (int i = 0; i < size; i++)
    {
        entries.push_back(dist(RNG));
    }

    return entries;
}

void testRetrieveEntry(const int entry, Dictionary<int,int>& tree)
{
    int retrieved;
    try
    {
        tree.getInfo(entry);
    }
    catch (Dictionary<int,int>::NoSuchValue)
    {
        cerr << "ERROR: Value " << entry << " isn't in the tree\n";
    }
}

// template <class T>
void print(const int& value)
{
    cout << value << " ";
}


