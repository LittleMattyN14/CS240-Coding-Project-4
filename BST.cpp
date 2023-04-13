

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "BST.h"

using namespace std;



BST::BST()
{
    count = 0;
    root = NULL;
}

BST::BST(int x)
{
    count = 0;
    Node *temp = new Node(x);
    root = temp;
    nodeList.push_back(temp);
}

BST::~BST()
{
    removeNodes(root);
}

void BST::removeNodes(BST::Node* temp)
{
    if(temp->left != NULL)
    {
        removeNodes(temp->left);
    }
    if(temp->right != NULL)
    {
        removeNodes(temp->right);
    }
    delete temp;
}

bool BST::insert(int x)
{
    Node* temp = new Node(x);
    nodeList.push_back(temp);
    if(root == NULL)
    {
        root = temp;
        return true;
    }
    else
    {
        Node* curNode = root;
        while(curNode != NULL)
        {
            if(temp->val == curNode->val)
            {
                count++;
                return false;
            }
            else if(temp->val > curNode->val)
            {
               count++;
               if(curNode->right == NULL)
               {
                curNode->right = temp;
                curNode = NULL;
               }
               else{
                curNode = curNode->right;
               }
            }
            else
            {
               count++;
               if(curNode->left == NULL)
               {
                curNode->left = temp;
                curNode = NULL;
               }
               else{
                curNode = curNode->left;
               }
            }
        }
        return true;
    }
}

bool BST::insertVector(vector<int> &x)
{
    for(int i = 0; i < x.size(); i++)
    {
        insert(x.at(i));
    }
    return true;
}

bool BST::find(int x)
{
    Node* temp = root;
    while(temp != NULL)
    {
        if(x == temp->val)
        {
            return true;
        }
        if(x > temp->val)
        {
            temp = temp->right;
        }
        else if(x < temp->val)
        {
            temp = temp->left;
        }
    }
    return false;
}

int BST::remove(int x)
{
    if(!find(x))
    {
        return -1;
    }
    Node* parent = NULL;
    Node* temp = root;

    while(temp != NULL)
    {
        if(temp->val == x)
        {   
            if(temp->right == NULL && temp->left == NULL)
            {
                if(parent == NULL)
                {
                    root = NULL;
                }
                else if(parent->left == temp)
                {
                    parent->left = NULL;
                }
                else {
                    parent->right = NULL;
                }
            }
            else if(temp->right == NULL)
            {
                if(parent == NULL)
                {
                    root = temp->left;
                }
                else if(parent->left == temp)
                {
                    parent->left = temp->left;
                }
                else {
                    parent->right = temp->left;
                }
            }
            else if(temp->left == NULL)
            {
                if(parent == NULL)
                {
                    root = temp->right;
                }
                else if(parent->left == temp)
                {
                    parent->left = temp->right;
                }
                else {
                    parent->right = temp->right;
                }
            }
            else
            {
                Node* suc = temp->left;
                while(suc->right != NULL)
                {
                    suc = suc->right;
                }
                int data = suc->val;
                remove(data);
                temp->val = data;
            }
        }
        else if(x < temp->val)
        {
            parent = temp;
            temp = temp->left;
        }
        else 
        {
            parent = temp;
            temp = temp->right;
        }
    }
    return x;
    
}

bool BST::revmoveVector(vector<int> &x)
{
    for(int i = 0; i < x.size(); i++)
    {
        remove(x.at(i));
    }
    return true;
}

void BST::printStart()
{
    Node* temp = root;
    if(temp->left != NULL)
    {
        print(temp->left);
    }
    cout << temp->val << " ";
    if(temp->right != NULL)
    {
        print(temp->right);
    }

}

void BST::print(Node* temp)
{
    if(temp->left != NULL)
    {
        print(temp->left);
    }
    cout << temp->val << " ";
    if(temp->right != NULL)
    {
        print(temp->right);
    }
}

