#include "RedBlackTree.h"
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// The constructor
RedBlackTree::RedBlackTree()
{
    // :)
}

// The destructor
RedBlackTree::~RedBlackTree()
{
  while(this->Size()>0){
Remove(this->root->data);
  }
}

// Copy constructor
RedBlackTree::RedBlackTree(const RedBlackTree &rbtree)
{
    // new root node
    RBTNode *newNode = new RBTNode();
    if (rbtree.root != nullptr)
    {
        newNode->data = rbtree.root->data;
        newNode->color = rbtree.root->color;
        newNode->parent = nullptr;

        if (rbtree.root->left != nullptr)
        { // call the helper function to copy the rest of the children
            newNode->left = copyNode(rbtree.root->left, newNode);
        }
        else
        {
            newNode->left = nullptr;
        }

        if (rbtree.root->right != nullptr)
        { // call the helper function to copy the rest of the children
            newNode->right = copyNode(rbtree.root->right, newNode);
        }
        else
        {
            newNode->right = nullptr;
        }

        // decalre this new node as the root
        this->root = newNode;
    }
    else
    {
        this->root = nullptr;
    }

    // add to the vector to deallocate the pointers
    vecList.push_back(newNode);
}

// Helper fucntion to copy the rest of the tree after copying the root
// in the main copy contructor
RBTNode *RedBlackTree::copyNode(RBTNode *child, RBTNode *root)
{
    RBTNode *newNode = new RBTNode();
    newNode->data = child->data;
    newNode->color = child->color;
    newNode->parent = root;

    if (child->left != nullptr)
    {
        newNode->left = copyNode(child->left, newNode);
    }
    else
    {
        newNode->left = nullptr;
    }

    if (child->right != nullptr)
    {
        newNode->right = copyNode(child->right, newNode);
    }
    else
    {
        newNode->right = nullptr;
    }

    vecList.push_back(newNode);
    return newNode;
}

// Prints the tree in-order
string RedBlackTree::ToInfixString(RBTNode *root) const
{
    string str = "";
    string color;
    if (root == nullptr)
    {
        return "";
    }
    str += ToInfixString(root->left);
    if (root->color == COLOR_BLACK)
    {
        color = "B";
    }
    else if (root->color == COLOR_DOUBLEBLACK)
    {
        color = "BB";
    }
    else if (root->color == COLOR_RED)
    {
        color = "R";
    }
    // color = root->color == COLOR_BLACK ? "B" : "R";
    str += " " + color + to_string(root->data) + " ";
    str += ToInfixString(root->right);
    return str;
}

// Prints the tree pre-order
string RedBlackTree::ToPrefixString(RBTNode *root) const
{
    string str = "";
    string color;
    if (root == nullptr)
    {
        return "";
    }
    if (root->color == COLOR_BLACK)
    {
        color = "B";
    }
    else if (root->color == COLOR_DOUBLEBLACK)
    {
        color = "BB";
    }
    else if (root->color == COLOR_RED)
    {
        color = "R";
    }
    str += " " + color + to_string(root->data) + " ";
    str += ToPrefixString(root->left);
    str += ToPrefixString(root->right);
    return str;
}

// Prints the tree post-order
string RedBlackTree::ToPostfixString(RBTNode *root) const
{
    string str = "";
    string color;
    if (root == nullptr)
    {
        return "";
    }
    str += ToPostfixString(root->left);
    str += ToPostfixString(root->right);
    if (root->color == COLOR_BLACK)
    {
        color = "B";
    }
    else if (root->color == COLOR_DOUBLEBLACK)
    {
        color = "BB";
    }
    else if (root->color == COLOR_RED)
    {
        color = "R";
    }
    str += " " + color + to_string(root->data) + " ";
    return str;
}

// Returns the node with the smallest data
int RedBlackTree::GetMin()
{
    if (this->root == nullptr)
    {
        return 0;
    }

    bool minReached = false;
    RBTNode *currMin = this->root;

    // iterate until the left end is reached
    while (!minReached)
    {
        if (currMin->left != nullptr)
        {
            currMin = currMin->left;
        }
        else
        {
            minReached = true;
        }
    }
    return currMin->data;
}

// Returns the node with the largest data
int RedBlackTree::GetMax()
{

    if (this->root == nullptr)
    {
        return 0;
    }

    bool minReached = false;
    RBTNode *currMax = this->root;

    // iterate until the right end is reached
    while (!minReached)
    {
        if (currMax->right != nullptr)
        {
            currMax = currMax->right;
        }
        else
        {
            minReached = true;
        }
    }
    return currMax->data;
}

// check if the specific node exists inside the tree
bool RedBlackTree::Contains(int node)
{
    if (this->root == nullptr)
    {
        return false;
    }

    bool found = false;
    long long unsigned int currLength = 0;
    RBTNode *currNode = this->root;

    // iterate until the node is found or until the whole tree is traversed through
    while (!found)
    {
        if (currNode == nullptr)
        {
            return found;
        }

        if (currNode->data == node)
        {
            found = true;
            return found;
        }
        else if (currNode->data > node)
        {
            currNode = currNode->left;
        }
        else if (currNode->data < node)
        {
            currNode = currNode->right;
        }
        currLength++;
    }

    return found;
}

// Inserts a new node into the the tree
void RedBlackTree::Insert(int node)
{
    if (this->Contains(node))
    {
        throw invalid_argument("Caught an exception");
    }

    // declare a new node
    RBTNode *newNode = new RBTNode();
    // add this node to the list to deallocate it later
    vecList.push_back(newNode);

    newNode->data = node;
    RBTNode *currParent = nullptr;
    RBTNode *currRoot = this->root;

    // look for the parent
    while (currRoot != nullptr)
    {
        currParent = currRoot;
        if (currRoot->data > node)
        {
            currRoot = currRoot->left;
        }

        else if (currRoot->data < node)
        {
            currRoot = currRoot->right;
        }
    }

    newNode->parent = currParent;

    // Insert the node to its proper location
    if (currParent == nullptr)
    {
        newNode->color = COLOR_BLACK;
        this->root = newNode;
        numItems++;
        return;
    }
    else
    {
        newNode->color = COLOR_RED;

        if (currParent->data > newNode->data)
        {
            currParent->left = newNode;
            numItems++;
        }
        else if (currParent->data < newNode->data)
        {
            currParent->right = newNode;
            numItems++;
        }
    }

    // Readjust/Fix the tree after inserting the node
    while (newNode->parent->color == COLOR_RED)
    {
        if (newNode->parent == newNode->parent->parent->left)
        { // if the parent is on the left of its parent
            if (newNode->parent->parent->right == nullptr || newNode->parent->parent->right->color == COLOR_BLACK)
            { // if the uncle is black or NULL
                if (newNode->parent->right == newNode)
                { // if the newnode is on the left side of its parent
                    newNode = newNode->parent;
                    LeftRotate(newNode);
                    newNode->parent->color = COLOR_BLACK;
                    newNode->parent->parent->color = COLOR_RED;
                    RightRotate(newNode->parent->parent);
                }
                else if (newNode->parent->left == newNode)
                {
                    newNode->parent->color = COLOR_BLACK;
                    newNode->parent->parent->color = COLOR_RED;
                    RightRotate(newNode->parent->parent);
                }
            }
            else if (newNode->parent->parent->right->color == COLOR_RED)
            { // if the uncle is red - STEP6
                newNode->parent->parent->right->color = COLOR_BLACK;
                newNode->parent->color = COLOR_BLACK;
                if (newNode->parent->parent != this->root)
                {
                    newNode->parent->parent->color = COLOR_RED;
                }
                newNode = newNode->parent->parent;
            }
        }

        else if (newNode->parent == newNode->parent->parent->right)
        { // if the parent is on the right of its parent
            if (newNode->parent->parent->left == nullptr || newNode->parent->parent->left->color == COLOR_BLACK)
            { // if the uncle is black or NULL
                if (newNode->parent->left == newNode)
                { // if the newnode is on the right side of its parent
                    newNode = newNode->parent;
                    RightRotate(newNode);
                    newNode->parent->parent->color = COLOR_RED;
                    newNode->parent->color = COLOR_BLACK;
                    LeftRotate(newNode->parent->parent);
                }
                else if (newNode->parent->right == newNode)
                {
                    newNode->parent->parent->color = COLOR_RED;
                    newNode->parent->color = COLOR_BLACK;
                    LeftRotate(newNode->parent->parent);
                }
            }
            else if (newNode->parent->parent->left->color == COLOR_RED)
            { // if the uncle is red
                newNode->parent->color = COLOR_BLACK;
                newNode->parent->parent->left->color = COLOR_BLACK;
                if (newNode->parent->parent != this->root)
                {
                    newNode->parent->parent->color = COLOR_RED;
                }
                newNode = newNode->parent->parent;
            }
        }
        // if the newNode is the root, no need to check if its parent is red
        if (newNode == root)
        {
            break;
        }
        // The root should always be black
        this->root->color = COLOR_BLACK;
    }
}

void RedBlackTree::DeleteNode(RBTNode *node)
{
    for (size_t i = 0; i < this->vecList.size(); i++)
    {
        if (vecList.at(i) == node)
        {
            vecList.erase(vecList.begin() + i);
        }
    }
    delete node;
}

void RedBlackTree::ReplaceNode(RBTNode *PNode, RBTNode *CNode)
{
    if (PNode == PNode->parent->left)
    {
        PNode->parent->left = CNode;
    }

    if (PNode == PNode->parent->right)
    {
        PNode->parent->right = CNode;
    }
    CNode->parent = PNode->parent;
}

void RedBlackTree::Remove(int data)
{
    if (!this->Contains(data))
    {
        throw invalid_argument("Caught an exception");
    }

    RBTNode *currNode; 
    int currNodeColor;
    RBTNode *replaceNode = nullptr;
    bool found = false;
    RBTNode *node = this->root;
    RBTNode *inOrderSucc;
    RBTNode *newNullNode;

    while (!found)
    {
        if (node->data == data)
        {
            currNode = node;
            found = true;
        }

        else if (node->data > data)
        {
            node = node->left;
        }
        else if (node->data < data)
        {
            node = node->right;
        }
    }

    currNodeColor = currNode->color;

    if (currNode->right == nullptr && currNode->left != nullptr)
    {
        this->ReplaceNode(currNode, currNode->left);
        currNode->left->parent = currNode->parent;
        replaceNode = currNode->left;
        DeleteNode(currNode);
    }
    else if (currNode->left == nullptr && currNode->right != nullptr)
    { 
        ReplaceNode(currNode, currNode->right);
        currNode->right->parent = currNode->parent;
        replaceNode = currNode->right;
        DeleteNode(currNode);
    }
    else if (currNode->left == nullptr && currNode->right == nullptr)
    { 
        newNullNode = new RBTNode();
        newNullNode->color = COLOR_DOUBLEBLACK;
        ReplaceNode(currNode, newNullNode);
        vecList.push_back(newNullNode);
        replaceNode = newNullNode;
        DeleteNode(currNode);
        
    }
    else if (currNode->left != nullptr && currNode->right != nullptr)
    {
        inOrderSucc = currNode->right;

        while (inOrderSucc->left != nullptr)
        {
            inOrderSucc = inOrderSucc->left;
        }
 
        currData = inOrderSucc->data;
        replaceNode = inOrderSucc; 
        Remove(currData);
        currNode->data = currData; 
    }



    if (replaceNode == this->root || currNodeColor == 1 || replaceNode->color == 1) // done
    {  
        if (replaceNode->color == COLOR_DOUBLEBLACK)
        {
            if (replaceNode == replaceNode->parent->left)
            {
                replaceNode->parent->left = nullptr;
            }

            if (replaceNode == replaceNode->parent->right)
            {
                replaceNode->parent->right = nullptr;
            }
            DeleteNode(replaceNode);

        }
        else
        {
            replaceNode->color = 0;
        }
    }
    else if ((replaceNode->color == COLOR_BLACK ||
              replaceNode->color == COLOR_DOUBLEBLACK) &&
             (currNodeColor == COLOR_BLACK))
    {
        replaceNode->color = COLOR_DOUBLEBLACK;
        FixDoubleBlack(replaceNode);
    }

    
}

void RedBlackTree::FixDoubleBlack(RBTNode *doubleBlNode)
{
    RBTNode *sibling;
    bool siblingHasRedRight = false;
    bool siblingHasRedLeft = false;
    if (doubleBlNode != this->root && doubleBlNode->color != COLOR_BLACK)
    {
        if (doubleBlNode == doubleBlNode->parent->left)
        {
            sibling = doubleBlNode->parent->right;

            if (sibling->color == COLOR_BLACK)
            {
                siblingHasRedRight = (sibling != nullptr && sibling->right != nullptr && sibling->right->color == COLOR_RED);
                siblingHasRedLeft = (sibling != nullptr && sibling->left != nullptr && sibling->left->color == COLOR_RED);

                if ((!siblingHasRedRight) && (!siblingHasRedLeft))
                {
                    // cout << "A1" << endl;
                    sibling->color = COLOR_RED;
                    doubleBlNode->parent->left = nullptr;
                    DeleteNode(doubleBlNode);
                    
                    if (sibling->parent->color == COLOR_BLACK)
                    {
                        sibling->parent->color = COLOR_DOUBLEBLACK;
                        FixDoubleBlack(sibling->parent);
                    }
                    else if (sibling->parent->color == COLOR_RED)
                    {
                        sibling->parent->color = COLOR_BLACK;
                    }
                }
                else
                {
                    if (siblingHasRedRight)
                    {
                        // cout << "A3" << endl;
                        sibling->color = sibling->parent->color;
                        sibling->parent->color = COLOR_BLACK;
                        sibling->right->color = COLOR_BLACK;
                        LeftRotate(sibling->parent);
                         doubleBlNode->parent->left = nullptr;
                        DeleteNode(doubleBlNode);
                       
                    }
                    else if (siblingHasRedLeft)
                    {
                        // cout << "A2" << endl;
                        sibling->left->color = doubleBlNode->parent->color;
                        sibling->parent->color = COLOR_BLACK;
                        RightRotate(sibling);
                        LeftRotate(sibling->parent);
doubleBlNode->parent->left = nullptr;
                        DeleteNode(doubleBlNode);
                        
                    }
                }
            }
            else if (sibling->color == COLOR_RED)
            {
                // cout << "A4" << endl;
                sibling->parent->color = COLOR_RED;
                sibling->color = COLOR_BLACK;
                LeftRotate(sibling->parent);
                FixDoubleBlack(doubleBlNode);
            }
        }

        else if (doubleBlNode == doubleBlNode->parent->right)
        {
            sibling = doubleBlNode->parent->left;
            if (sibling->color == COLOR_BLACK)
            {
                siblingHasRedRight = (sibling != nullptr && sibling->right != nullptr && sibling->right->color == COLOR_RED);
                siblingHasRedLeft = (sibling != nullptr && sibling->left != nullptr && sibling->left->color == COLOR_RED);

                if ((!siblingHasRedRight) && (!siblingHasRedLeft))
                {
                    // cout << "A5" << endl;
                    sibling->color = COLOR_RED;
                    doubleBlNode->parent->right = nullptr;
                    DeleteNode(doubleBlNode);
                    
                    if (sibling->parent->color == COLOR_BLACK)
                    {
                        sibling->parent->color = COLOR_DOUBLEBLACK;
                        FixDoubleBlack(sibling->parent);
                    }
                    else if (sibling->parent->color == COLOR_RED)
                    {
                        sibling->parent->color = COLOR_BLACK;
                    }
                }
                else
                {

                    if (siblingHasRedLeft)
                    {
                        // cout << "A6" << endl;
                        sibling->color = sibling->parent->color;
                        sibling->parent->color = COLOR_BLACK;
                        sibling->left->color = COLOR_BLACK;
                        RightRotate(sibling->parent);
                          doubleBlNode->parent->right = nullptr;
                        DeleteNode(doubleBlNode);
                      
                    }
                    else if (siblingHasRedRight)
                    {
                        // cout << "A7" << endl;
                        sibling->right->color = doubleBlNode->parent->color;
                        sibling->parent->color = COLOR_BLACK;
                        LeftRotate(sibling);
                        RightRotate(sibling->parent);
    doubleBlNode->parent->right = nullptr;
                        DeleteNode(doubleBlNode);
                    
                    }
                }
            }
            else if (sibling->color == COLOR_RED)
            {
                // cout << "A8" << endl;
                sibling->parent->color = COLOR_RED;
                sibling->color = COLOR_BLACK;
                RightRotate(sibling->parent);
                FixDoubleBlack(doubleBlNode); 
            }
        }
     
    }
                          
 
}
 

// perform right rotate on the passed node
void RedBlackTree::RightRotate(RBTNode *node)
{ // we are passing the grandparent

    RBTNode *currNode = node->left;

    node->left = nullptr; //
    if (currNode->right != nullptr)
    {
        node->left = currNode->right;
        currNode->right->parent = node;
    }

    currNode->right = node;

    if (node->parent == nullptr)
    {
        currNode->parent = nullptr;
        this->root = currNode;
    }
    else if (node->parent->left == node)
    {
        currNode->parent = node->parent;
        node->parent->left = currNode;
    }
    else if (node->parent->right == node)
    {
        currNode->parent = node->parent;
        node->parent->right = currNode;
    }
    node->parent = currNode;
}

// returns the size of the tree(its nodes)
int RedBlackTree::Size()
{
    return numItems;
}

// perform left rotate on the passed node
void RedBlackTree::LeftRotate(RBTNode *node)
{ // we are passing the parent

    RBTNode *currNode = node->right;

    node->right = nullptr;
    if (currNode->left != nullptr)
    {
        node->right = currNode->left;
        currNode->left->parent = node;
    }

    currNode->left = node;

    if (node->parent == nullptr)
    {
        currNode->parent = nullptr;
        this->root = currNode;
    }
    else if (node->parent->right == node)
    {
        currNode->parent = node->parent;
        node->parent->right = currNode;
    }
    else if (node->parent->left == node)
    {
        currNode->parent = node->parent;
        node->parent->left = currNode;
    }
    node->parent = currNode;
}
