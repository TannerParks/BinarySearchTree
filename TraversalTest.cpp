#include <iostream>
#include "BSTnode.h"

using namespace std;


//display tree
int display_inorder(BSTnode *node){
    //cout << "Node Value" << node->value << endl;
    if (node != nullptr){
        display_inorder(node->left);
        cout << node->value << endl;
        display_inorder(node->right);
    }
    return 0;
}
int display_preorder(BSTnode *node){
    if (node != nullptr){
        cout << node->value << endl;
        display_preorder(node->left);
        display_preorder(node->right);
    }
    return 0;
}
int display_postorder(BSTnode *node){
    if (node != nullptr){
        display_postorder(node->left);
        display_postorder(node->right);
        cout << node->value << endl;
    }
    return 0;
}

int main(){
    BSTnode *root = nullptr;
    root = new BSTnode(50);
    root->left = new BSTnode(30);
    root->left->left = new BSTnode(20);
    //root->left->left->left = new BSTnode(10);
    root->left->right = new BSTnode(40);
    root->right = new BSTnode(70);
    root->right->left = new BSTnode(60);
    root->right->right = new BSTnode(80);
    //display_inorder(root);
    //display_preorder(root);
    display_postorder(root);
}