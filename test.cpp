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
    tree.printStart();

    return 0;
}