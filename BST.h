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
     bool shuffle(int);
     bool shake(int, int);
     int averageDepth();
     int depth();
     bool reset();
     int getCount();
     BST &operator=(const BST &other);

    private:
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
     vector<Node*> nodeList;
};
