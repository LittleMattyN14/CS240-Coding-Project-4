#include <iostream>
#include <stdlib.h>

#include "BST.h"

using namespace std;

int main()
{
    BST tree1;
    tree1.insert(50);
    tree1.insert(25);
    tree1.insert(75);
    tree1.insert(30);
    tree1.insert(35);
    tree1.insert(80);
    tree1.insert(70);
    tree1.insert(10);
    tree1.insert(5);
    tree1.insert(100);

    cout << tree1.find(80) << endl;
    cout << tree1.find(70) << endl;
    cout << tree1.find(1000) << endl;

    
    

    /*tree1.remove(5);
    tree1.remove(30);
    tree1.remove(75);
    tree1.remove(50);*/
    cout << endl;
    tree1.printStart();
    cout << "Tree height: " << tree1.getHeight() << endl;
    cout << "Tree count: " << tree1.getCount() << endl;
    cout << "Average depth: " << tree1.averageDepth() << endl;
    cout << endl;

    tree1.shuffle(5);
    vector<int> newTree3List, newTree4List;
    newTree3List = tree1.getList();
    BST tree3, tree4;
    tree3.insertVector(newTree3List);
    tree3.printStart();
    cout << "Tree height: " << tree3.getHeight() << endl;
    cout << "Tree count: " << tree3.getCount() << endl;
    cout << "Average depth: " << tree3.averageDepth() << endl;

    cout << endl;

    tree3.shake(5, 10);
    newTree4List = tree3.getList();
    tree4.insertVector(newTree4List);
    tree4.printStart();
    cout << "Tree height: " << tree4.getHeight() << endl;
    cout << "Tree count: " << tree4.getCount() << endl;
    cout << "Average depth: " << tree4.averageDepth() << endl;

    cout << endl;

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
    tree2.removeVector(x1);
    tree2.removeVector(x2);

    cout << endl;
    tree2.printStart();

    return 0;
}