#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;
class BST{
    public:
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
     BST();
     BST(int);
     ~BST();
     bool insert(int);
     bool find(int);
     int remove(int);
     bool insertVector(vector<int> &);
     bool removeVector(vector<int> &);
     void printStart();
     bool shuffle(int);
     bool shake(int, int);
     double averageDepth();
     double depthRecursive(Node*);
     double nodeCountRecursive(Node*);
     void reset();
     int getCount();
     BST &operator=(const BST &other);
     int count;
     Node* root;
     void removeNodes(Node*);
     void print(Node*);
     int depth(Node*);
     int getHeight();
     vector<int> getList();
     vector<Node*> nodeList;
};
