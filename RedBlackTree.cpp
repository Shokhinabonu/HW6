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
                {
                    newNode->parent->color = COLOR_BLACK;
                    newNode->parent->parent->color = COLOR_RED;
                    RightRotate(newNode->parent->parent);
                }
                else if (newNode->parent->right == newNode)
                { 
                    newNode->color=COLOR_BLACK;
                       newNode->parent->parent->color = COLOR_RED;
                    LeftRotate(newNode->parent); 
                  RightRotate(newNode->parent); 
                }
            }
            // else if (newNode->parent->parent->right != nullptr)
            // { // if the right child of the grandparent exists
            //     if (newNode->parent->parent->right->color == COLOR_RED)
            //     { // and if it is red
            //         newNode->parent->parent->right->color = COLOR_BLACK;
            //         newNode->parent->parent->left->color = COLOR_BLACK;
            //         newNode->parent->parent->color = COLOR_RED;

            //         RBTNode *currNode = newNode->parent->parent;
            //         newNode->parent->parent = newNode; // just the data?
            //         newNode = currNode;
            //     }
            // }
            else if (newNode->parent->right == newNode)
            {
                // int data = newNode->parent->data;
                // newNode->parent->data = newNode->data;
                // newNode->data = data;
                // LeftRotate(newNode->parent->parent);
                // RightRotate(newNode->parent->parent);
            }
        }
if(newNode==root){
break;
}
        
    }
}

void RedBlackTree::RightRotate(RBTNode *node)
{

    RBTNode *currNode = node->left;
    
    this->root = currNode;
    node->left = nullptr;
    node->parent = currNode;
     
    currNode->parent = nullptr;

    currNode->right = node; 
 
}

void RedBlackTree::LeftRotate(RBTNode *node)
{
   
    RBTNode *newParentNode = node->parent;

    RBTNode *currNode = node->right;

    node->parent = currNode;
    node->right = nullptr;

    currNode->parent = newParentNode;
    newParentNode->left = currNode;
    currNode->left = node;

    // cout << "rbt: " << newParentNode->left->data << endl;
    // cout << "rbt: " << ToPostfixString() << endl;
}