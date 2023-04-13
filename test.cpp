#include <iostream>
#include <stdlib.h>

#include "BST.h"

using namespace std;

int main()
{
    BST tree;
    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    tree.insert(30);
    tree.insert(35);
    tree.insert(80);
    tree.insert(70);
    tree.insert(10);
    tree.insert(5);
    tree.insert(100);

    cout << tree.find(80) << endl;
    cout << tree.find(70) << endl;
    cout << tree.find(1000) << endl;

    tree.remove(5);
    tree.remove(30);
    tree.remove(75);
    tree.remove(50);
    tree.printStart();


    BST tree2;
    tree2.insert(10);
    vector<int> x;
    
    
    x.push_back(50);
    x.push_back(25);
    x.push_back(30);
    x.push_back(70);
    x.push_back(75);
    x.push_back(80);

    tree2.insertVector(x);
    tree2.insert(100);
    tree2.revmoveVector(x);

    cout << endl;
    tree2.printStart();

    return 0;
}