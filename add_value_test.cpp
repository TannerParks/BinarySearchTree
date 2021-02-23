#include <iostream>
#include "BSTnode.h"

using namespace std;


//BSTnode *create_node(int new_value){   
//    BSTnode *newNode = new BSTnode;
//    newNode->value = new_value;
//    newNode->left = nullptr;
//    newNode->right = nullptr;
//    return newNode;
//}   
BSTnode *add_value(BSTnode *node, int new_value){
    if (node == nullptr){
        //return create_node(new_value);
        //BSTnode *newNode = new BSTnode(new_value);
        return new BSTnode(new_value);
    }
    else if (new_value <= node->value){
        node->left = add_value(node->left, new_value); 
    }
    else{
        node->right = add_value(node->right, new_value);   
    }
    return node;
    // if equal display message saying it's already in the tree
}
//display tree
    int display(BSTnode *node){
        cout << "Display" << endl;
        cout << node->value << endl;
        cout << node->left->value << endl;
        cout << node->right->value << endl;
        cout << node->left->left->value << endl;

        return 0;
    }

int main(){
    BSTnode *root = nullptr;
    root = add_value(root, 50);
    add_value(root, 40);
    add_value(root, 60);
    add_value(root, 30);
    display(root);
}