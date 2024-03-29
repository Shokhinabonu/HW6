
#include <iostream>
#include <vector>
#include <map>

#define COLOR_RED 1
#define COLOR_BLACK 0
#define COLOR_DOUBLEBLACK 2

using namespace std;

struct RBTNode
{
    int data;
    unsigned short int color;//change back to nothing
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
    void Remove(int data);

    bool Contains(int node);

    int GetMin();

    int GetMax();

    int Size();

    string ToInfixString() const { return ToInfixString(this->root); };
    string ToPrefixString() const { return ToPrefixString(this->root); };
    string ToPostfixString() const { return ToPostfixString(this->root); };

private:
    RBTNode *root = nullptr;
    unsigned long long int numItems = 0;
    vector<RBTNode *> vecList;
    int currData;

    string ToInfixString(RBTNode *root) const;
    string ToPrefixString(RBTNode *root) const;
    string ToPostfixString(RBTNode *root) const;

    void RightRotate(RBTNode *node);
    void LeftRotate(RBTNode *node);

    RBTNode *copyNode(RBTNode *child, RBTNode *root);

    void DeleteNode(RBTNode *node);
    void ReplaceNode(RBTNode *PNode, RBTNode *CNode);

    void FixDoubleBlack(RBTNode *doubleBlNode);
};