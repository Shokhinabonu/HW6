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
    str += ToPrefixString(root->left);
    str += ToPrefixString(root->right);
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
    str += ToPostfixString(root->left);
    str += ToPostfixString(root->right);
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
                if (newNode->parent->left == newNode)
                { // if the newnode is on the left side of its parent

                    newNode->parent->color = COLOR_BLACK;
                    newNode->parent->parent->color = COLOR_RED;
                    RightRotate(newNode->parent->parent);
                }
                else if (newNode->parent->right == newNode)
                { // if the newnode is on the right side of its parent
                    newNode->color = COLOR_BLACK;
                    newNode->parent->parent->color = COLOR_RED;
                    LeftRotate(newNode->parent);
                    RightRotate(newNode->parent);
                }
            }
            else if (newNode->parent->parent->right->color == COLOR_RED)
            {
                newNode->parent->parent->color = COLOR_BLACK;
                newNode->parent->parent->right->color = COLOR_BLACK;
                newNode->parent->parent->left->color = COLOR_BLACK;
                newNode = newNode->parent->parent;
            }
        }
        else if (newNode->parent == newNode->parent->parent->right)
        {
            if (newNode->parent->parent->left == nullptr)
            {
                if (newNode->parent->right == newNode)
                {
                    newNode->parent->color = COLOR_BLACK;
                    newNode->parent->parent->color = COLOR_RED;
                    RightRotate(newNode->parent->parent);
                }
                else if (newNode->parent->left == newNode)
                {
                    newNode->color = COLOR_BLACK;
                    newNode->parent->parent->color = COLOR_RED;
                    LeftRotate(newNode->parent);
                    RightRotate(newNode->parent);
                }
            }
            else if (newNode->parent->parent->left->color == COLOR_RED)
            {
                newNode->parent->parent->color = COLOR_BLACK;
                newNode->parent->parent->right->color = COLOR_BLACK;
                newNode->parent->parent->left->color = COLOR_BLACK;
                newNode = newNode->parent->parent;
            }
        }

        if (newNode == root)
        {
            break;
        }

        this->root->color = COLOR_BLACK;
    }
}

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

void RedBlackTree::LeftRotate(RBTNode *node)
{ // we are passing the parent

    RBTNode *currNode = node->right;

    node->right = nullptr; //
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