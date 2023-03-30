

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
    while(!nodeList.empty())
    {
        Node* temp = nodeList.back();
        nodeList.pop_back();
        delete temp;
        
    }
}


bool BST::insert(int x)
{
    Node* temp = new Node(x);
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


