#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;
class BST{
    public:
     BST();
     BST(int);
     ~BST();
     bool insert(int);
     bool find(int);
     int remove(int);
     bool insertVector(vector<int> &);
     bool revmoveVector(vector<int> &);
     void printStart();
     bool shuffle(int);
     bool shake(int, int);
     int averageDepth();
     
     void reset();
     int getCount();
     BST &operator=(const BST &other);

    class Node{
        public:
        int val;
        Node* left;
        Node* right;
        Node(){
            left = NULL;
            right = NULL;
        }
        Node(int x){
            val = x;
            left = NULL;
            right = NULL;
        }
    };
     int count;
     Node* root;
     void removeNodes(Node*);
     void print(Node*);
     int depth(Node*);
     vector<Node*> nodeList;
};
