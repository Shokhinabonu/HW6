
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
    RedBlackTree(const RBTNode &root);

    void Insert(int node);

    bool Contains(int node);

    int GetMin();

    int GetMax();

    int Size;

    string ToInfixString() const { return ToInfixString(this->root); };
    string ToPrefixString() const { return ToPrefixString(this->root); };
    string ToPostfixString() const { return ToPostfixString(this->root); };

private:
    RBTNode *root = nullptr;
    unsigned long long int numItems = 0;

    string ToInfixString(RBTNode *root) const;
    string ToPrefixString(RBTNode *root) const;
    string ToPostfixString(RBTNode *root) const;

    void RightRotate(RBTNode *node);
};