
#include <iostream>
#include <vector>
#include <map>

#define COLOR_RED 1
#define COLOR_BLACK 0

using namespace std;

struct RBTNode
{
    int data;
    unsigned short int color;
    RBTNode *parent = nullptr;
    RBTNode *left = nullptr;
    RBTNode *right = nullptr;
};

class RedBlackTree
{
public:
    RedBlackTree();
    RedBlackTree(const RedBlackTree &rbtree);
    ~RedBlackTree();

    void Insert(int node);

    bool Contains(int node);
    // while loop check the left and right child, compare the values

    int GetMin();
    // reach the left side of the tree
    int GetMax();

    int Size;

    string ToInfixString() const { return ToInfixString(this->root); };
    string ToPrefixString() const { return ToPrefixString(this->root); };
    string ToPostfixString() const { return ToPostfixString(this->root); };

private:
    RBTNode *root = nullptr;
    unsigned long long int numItems = 0;
    vector<RBTNode *> vecList;

    string ToInfixString(RBTNode *root) const;
    string ToPrefixString(RBTNode *root) const;
    string ToPostfixString(RBTNode *root) const;

    void RightRotate(RBTNode *node);
    void LeftRotate(RBTNode *node);

    RBTNode *copyNode(RBTNode *child, RBTNode *root);
};