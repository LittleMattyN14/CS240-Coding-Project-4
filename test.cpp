//Matthew Nieto and Thomas Parangelo

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
    cout << "Tree 1 count inserting into tree: " << tree1.getCount() << endl;
    tree1.reset();

    cout << "80 found: " << tree1.find(80) << endl;
    cout << "Tree 1 count find 80: " << tree1.getCount() << endl;
    tree1.reset();
    cout << "70 found: " << tree1.find(70) << endl;
    cout << "Tree 1 count find 70: " << tree1.getCount() << endl;
    tree1.reset();
    cout << "1000 found: " << tree1.find(1000) << endl;
    cout << "Tree 1 count find 1000: " << tree1.getCount() << endl;
    tree1.reset();

    
    

    tree1.remove(5);
    tree1.remove(30);
    tree1.remove(75);
    tree1.remove(50);
    cout << endl;
    tree1.printStart();
    cout << "Tree height: " << tree1.getHeight() << endl;
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
    tree3.reset();
    tree3.find(80);
    cout << "Tree 3 count find 80: " << tree3.getCount() << endl;
    tree3.reset();
    tree3.find(70);
    cout << "Tree 3 count find 70: " << tree3.getCount() << endl;
    tree3.reset();
    tree3.find(1000);
    cout << "Tree 3 count find 1000: " << tree3.getCount() << endl;
    tree3.reset();

    cout << endl;

    tree3.shake(5, 10);
    newTree4List = tree3.getList();
    tree4.insertVector(newTree4List);
    tree4.printStart();
    cout << "Tree height: " << tree4.getHeight() << endl;
    cout << "Tree count: " << tree4.getCount() << endl;
    cout << "Average depth: " << tree4.averageDepth() << endl;
    tree4.reset();
    tree4.find(80);
    cout << "Tree 4 count find 80: " << tree4.getCount() << endl;
    tree4.reset();
    tree4.find(70);
    cout << "Tree 4 count find 70: " << tree4.getCount() << endl;
    tree4.reset();
    tree4.find(1000);
    cout << "Tree 4 count find 1000: " << tree4.getCount() << endl;
    tree4.reset();

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
    tree2.printStart();
    cout << endl;
    tree2.insert(100);
    tree2.printStart();
    cout << endl;
    tree2.removeVector(x1);
    tree2.printStart();
    cout << endl;
    tree2.removeVector(x2);

    cout << endl;
    tree2.printStart();
    cout << "Tree 2 height: " << tree2.getHeight() << endl;
    cout << endl;

    BST tree5, tree6;
    tree5.printStart();

    tree5.insert(25);
    tree5.insert(15);
    tree5.insert(35);
    tree5.insert(5);
    tree5.insert(20);
    tree5.insert(30);
    tree5.insert(45);
    tree5.insert(3);
    tree5.insert(10);
    tree5.insert(17);
    tree5.insert(22);
    tree5.insert(27);
    tree5.insert(32);
    tree5.insert(40);
    tree5.insert(55);
    tree5.printStart();
    cout << "Tree 5 height: " << tree5.getHeight() << endl;
    cout << "Tree count: " << tree5.getCount() << endl;
    cout << "Average depth: " << tree5.averageDepth() << endl;
    tree5.reset();
    tree5.find(5);
    cout << "Tree 5 count find 5: " << tree5.getCount() << endl;
    tree5.reset();
    tree5.find(22);
    cout << "Tree 5 count find 22: " << tree5.getCount() << endl;
    tree5.reset();
    tree5.find(35);
    cout << "Tree 5 count find 35: " << tree5.getCount() << endl;
    tree5.reset();
    tree5.find(25);
    cout << "Tree 5 count find 25: " << tree5.getCount() << endl;
    tree5.reset();
    cout << endl;
    tree5.shake(20, 6);
    vector<int> shookethList = tree5.getList();
    tree6.insertVector(shookethList);
    tree6.printStart();
    cout << "Tree 6 height: " << tree6.getHeight() << endl;
    cout << "Tree count: " << tree6.getCount() << endl;
    cout << "Average depth: " << tree6.averageDepth() << endl;
    tree6.reset();
    tree6.find(5);
    cout << "Tree 6 count find 5: " << tree6.getCount() << endl;
    tree6.reset();
    tree6.find(22);
    cout << "Tree 6 count find 22: " << tree6.getCount() << endl;
    tree6.reset();
    tree6.find(35);
    cout << "Tree 6 count find 35: " << tree6.getCount() << endl;
    tree6.reset();
    tree6.find(25);
    cout << "Tree 6 count find 25: " << tree6.getCount() << endl;
    tree6.reset();

    BST tree7, tree8;

    //test operations on empty tree
    tree7.remove(2);
    vector<int> vectorInt;
    tree7.removeVector(vectorInt);
    tree7.find(2);
    tree7.getHeight();
    tree7.shake(2, 2);
    tree7.shuffle(2);

    for(int i = 1; i <= 1000; i++){
        tree7.insert(i);
        tree8.insert(i);
    }
    tree7.reset();
    tree8.shuffle(1000);
    vector<int> tree8Vector;
    tree8Vector = tree8.getList();
    tree8.removeVector(tree8Vector);
    tree8.insertVector(tree8Vector);
    tree8.reset();
    cout << "Tree 7 height: " << tree7.getHeight() << endl;
    cout << "Tree 7 average depth: " << tree7.averageDepth() << endl;
    cout << "Tree 8 height: " << tree8.getHeight() << endl;
    cout << "Tree 8 average depth: " << tree8.averageDepth() << endl;
    for(int i = 10; i <= 1000; i += 10){
        tree7.find(i);
        tree8.find(i);
    }
    cout << "Tree 7 find count: " << tree7.getCount() << endl; //count to find every node
    cout << "Tree 8 find count: " << tree8.getCount() << endl;

    return 0;
}