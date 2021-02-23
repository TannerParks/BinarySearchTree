#include <iostream>
#include "BSTnode.h"

using namespace std;

BSTnode *find_minimum(BSTnode *node){
    BSTnode *current = node;
    while (current->left != nullptr){
        current = current->left;
    }
    return current;
}

BSTnode *remove_node(BSTnode *root, int value){
    if (root == nullptr){   //goes here if the tree is empty
        cout << "The tree is empty" << endl;    
        return root;
    }
    if (value < root->value){
        root->left = remove_node(root->left, value);
    }
    else if (value > root->value){
        root->right = remove_node(root->right, value);
    }
    else {
        if (root->left == nullptr) {
            BSTnode* temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == nullptr) {
            BSTnode* temp = root->left;
            delete(root);
            return temp;
        }
        BSTnode *temp = find_minimum(root->right);
        root->value = temp->value;
        root->right = remove_node(root->right, temp->value);
    }
    return root;
}


int display_inorder(BSTnode *node){
    //cout << "Node Value" << node->value << endl;
    if (node != nullptr){
        display_inorder(node->left);
        cout << node->value << endl;
        display_inorder(node->right);
    }
    return 0;
}

int main(){
    BSTnode *root = nullptr;
    root = new BSTnode(50);
    root->left = new BSTnode(30);
    root->left->left = new BSTnode(20);
    root->left->right = new BSTnode(40);
    root->right = new BSTnode(70);
    root->right->left = new BSTnode(60);
    root->right->right = new BSTnode(80);
    display_inorder(root);
    remove_node(root, 40);
    display_inorder(root);
}