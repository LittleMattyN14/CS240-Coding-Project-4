#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "BST.h"

using namespace std;



BST::BST()
{
    count = 0;
    root = NULL;
    srand((unsigned) time(NULL));
}

BST::BST(int x)
{
    count = 0;
    Node *temp = new Node(x);
    root = temp;
    nodeList.push_back(temp);
    srand((unsigned) time(NULL));
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
            count++;
            return true;
        }
        else if(x > temp->val)
        {
            count++;
            temp = temp->right;
        }
        else
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
            count++;
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
            return x;
        }
        else if(x < temp->val)
        {
            count++;
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
    if(temp->right != NULL){
        cout << "Node " << temp->val << " right child: " << temp->right->val << endl;
    }
    if(temp->left != NULL){
        cout << "Node " << temp->val << " left child: " << temp->left->val << endl;
    }
    if(temp->left == NULL && temp->right == NULL){
        cout << "Node " << temp->val << " is a leaf node with no children :(" << endl;
    }
    //cout << temp->val << " ";
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
    if(temp->right != NULL){
        cout << "Node " << temp->val << " right child: " << temp->right->val << endl;
    }
    if(temp->left != NULL){
        cout << "Node " << temp->val << " left child: " << temp->left->val << endl;
    }
    if(temp->left == NULL && temp->right == NULL){
        cout << "Node " << temp->val << " is a leaf node with no children :(" << endl;
    }
    //cout << temp->val << " ";
    if(temp->right != NULL)
    {
        print(temp->right);
    }
}

void BST::reset()
{
    count = 0;
}

int BST::getCount()
{
    return count;
}

int BST::averageDepth()
{
    int total = 0;
    return total;
}

int BST::depth(Node* x)
{
    if(x == NULL)
    {
        return -1;
    }
    int leftheight = depth(x->left);
    int rightheight = depth(x->right);
    return 1 + max(leftheight, rightheight);
}

int BST::getHeight(){
    return depth(root);
}

bool BST::shuffle(int swaps)
{
    int rand1, rand2;
    Node* temp;
    if(nodeList.size() == 1)
    {
        return false;
    }
    
    for(int i = 0; i < swaps; i++)
    {
        rand1 = (rand() % nodeList.size() - 1);
        rand2 = (rand() % (nodeList.size() - 1));
        while(rand1 == rand2)
        {
            rand2 = (rand() % (nodeList.size() - 1));
        }
        temp = nodeList.at(rand1);
        nodeList.at(rand1) = nodeList.at(rand2);
        nodeList.at(rand2) = temp;
    }
    
    return true;
}
bool BST::shake(int swaps, int distance)
{
    int randIndex, randDistance, rightOrLeft;
    Node* temp;
    for(int i = 0; i < swaps; i++)
    {
        randIndex = (rand() % nodeList.size() - 1);
        randDistance = (rand() % distance) + 1;
        rightOrLeft = (rand() % 2);
            while(randIndex >= 1 && randIndex < nodeList.size() - 1){
                if(rightOrLeft == 0){
                    temp = nodeList.at(randIndex);
                    nodeList.at(randIndex) = nodeList.at(randIndex - 1);
                    nodeList.at(randIndex - 1) = temp;
                    randIndex--;
                }
            else{
                temp = nodeList.at(randIndex);
                nodeList.at(randIndex) = nodeList.at(randIndex + 1);
                nodeList.at(randIndex + 1) = temp;
                randIndex++;
            }
        }
    }
    return true;
}