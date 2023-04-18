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
    cout << "Tree height: " << tree.getHeight() << endl;
    cout << "Tree count: " << tree.getCount() << endl;


    BST tree2;
    tree2.insert(10);
    vector<int> x1, x2;
    
    
    x1.push_back(50);
    x1.push_back(25);
    x1.push_back(30);
    x1.push_back(70);
    x1.push_back(75);
    x1.push_back(80);

    x2.push_back(25);
    x2.push_back(800);
    x2.push_back(10);

    tree2.insertVector(x1);
    tree2.insert(100);
    tree2.revmoveVector(x1);
    tree2.revmoveVector(x2);

    cout << endl;
    tree2.printStart();

    return 0;
}