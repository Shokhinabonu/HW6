#include "RedBlackTree.h"
#include <iostream>
#include <cassert>

using namespace std;

RedBlackTree::RedBlackTree()
{
}

string RedBlackTree::ToInfixString(RBTNode *root) const
{
    string str = "";
    string color;
    if (root == nullptr)
    {
        return "";
    }
    str += ToInfixString(root->left);
    color = root->color == COLOR_BLACK ? "B" : "R";
    str += " " + color + to_string(root->data) + " ";
    str += ToInfixString(root->right);
    return str;
}

string RedBlackTree::ToPrefixString(RBTNode *root) const
{
    string str = "";
    string color;
    if (root == nullptr)
    {
        return "";
    }
    color = root->color == COLOR_BLACK ? "B" : "R";
    str += " " + color + to_string(root->data) + " ";
    str += ToInfixString(root->left);
    str += ToInfixString(root->right);
    return str;
}

string RedBlackTree::ToPostfixString(RBTNode *root) const
{
    string str = "";
    string color;
    if (root == nullptr)
    {
        return "";
    }
    str += ToInfixString(root->left);
    str += ToInfixString(root->right);
    color = root->color == COLOR_BLACK ? "B" : "R";
    str += " " + color + to_string(root->data) + " ";
    return str;
}

void RedBlackTree::Insert(int node)
{
    RBTNode *newNode = new RBTNode();
    newNode->data = node;

    RBTNode *currParent = nullptr;
    RBTNode *currRoot = this->root;
    while (currRoot != nullptr)
    {
        if (currRoot->data > node)
        {
            currRoot = currRoot->left;
        }

        else if (currRoot->data < node)
        {
            currRoot = currRoot->right;
        }

        currParent = currRoot;
    }

    if (currParent == nullptr)
    {
        newNode->color = COLOR_BLACK;
        this->root = newNode;
        return;
        
    }
    else
    {
        newNode->color = COLOR_RED;
        newNode->parent = currParent;

        if (currParent->data > newNode->data)
        {
            currParent->left = newNode;
        }
        if (currParent->data < newNode->data)
        {
            currParent->right = newNode;
        }

        currRoot->parent = currParent;
    }
}

// void RedBlackTree::InsertRecursiveHelper(RBTNode *currRoot, int currNodeData)
// {
// if (currRoot = nullptr)
// {
//     root->data = currNodeData;
//     root->color = COLOR_BLACK;
//     return;
// }

// if (currRoot->data > currNodeData){
//     InsertRecursiveHelper
// }
// }