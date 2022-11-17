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
        // cout << "current int: " << this->root->data << endl;
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

    if (currParent == nullptr)
    {
        newNode->color = COLOR_BLACK;
        this->root = newNode;
        return;
    }
    else
    {
        newNode->color = COLOR_RED;

        if (currParent->data > newNode->data)
        {

            currParent->left = newNode;
        }
        else if (currParent->data < newNode->data)
        {
            currParent->right = newNode;
        }
    }

    while (newNode->parent->color == COLOR_RED)
    {
        if (newNode->parent == newNode->parent->parent->left)
        { // if the parent is on the left of its parent
            if (newNode->parent->parent->right == nullptr)
            { // if the uncle is black or NULL
                newNode->parent->color = COLOR_BLACK;
                newNode->parent->parent->color = COLOR_RED;
                RightRotate(newNode->parent->parent);
            }
        }
    }
}

void RedBlackTree::RightRotate(RBTNode *node)
{
    RBTNode *newRootNode = node->left;

    node->parent = newRootNode;
    newRootNode->right = node;
}
