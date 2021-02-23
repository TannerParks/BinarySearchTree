#include <iostream>
#include "BSTnode.h"

using namespace std;

//Add values
BSTnode *add_value(BSTnode *node, int new_value){
    //put value where nullptr is
    if (node == nullptr){
        return new BSTnode(new_value);
    }
    //value <= go left 
    else if (new_value <= node->value){
        node->left = add_value(node->left, new_value);
    }
    //value > go right
    else{
        node->right = add_value(node->right, new_value);    
    }
    return node;
    // if equal display message saying it's already in the tree
}
//Find minimum value on right side of tree to replace a node with two child nodes
BSTnode *find_minimum(BSTnode *node){
    BSTnode *current = node;
    while (current->left != nullptr){   //finds the leftmost value in the right side of the tree
        current = current->left;
    }
    return current;
}

//Remove values
BSTnode *remove_node(BSTnode *node, int value){
    if (node == nullptr){   //goes here if the tree is empty
        cout << "The tree is empty" << endl;    
        return node;
    }
    if (value < node->value){   //check left side if value is less than node
        node->left = remove_node(node->left, value);
    }
    else if (value > node->value){  //check right side if value is more than node
        node->right = remove_node(node->right, value);
    }
    else {
        //one or zero child nodes
        if (node->left == nullptr) {    //if left is null then...
            BSTnode* temp = node->right; //...replace with node->right
            delete(node);
            return temp;
        }
        else if (node->right == nullptr){   //if right is null then...
            BSTnode* temp = node->left; //...replace with node->left
            delete(node);
            return temp;
        }
        //both child nodes
        BSTnode *temp = find_minimum(node->right);  //finds the smallest value on the right side of tree (inorder)
        node->value = temp->value;
        node->right = remove_node(node->right, temp->value);    //deletes the value so there won't be a copy
    }
    return node;
}
//Display
int display_inorder(BSTnode *node){
    //starts at the leftmost then works its way right
    if (node != nullptr){
        display_inorder(node->left);    //stops when root->left = nullptr
        cout << node->value << endl;
        display_inorder(node->right);
    }
    return 0;
}
int display_preorder(BSTnode *node){
    //starts at the top then goes to the left subtree and then the right subtree
    if (node != nullptr){
        cout << node->value << endl;
        display_preorder(node->left);
        display_preorder(node->right);
    }
    return 0;
}
int display_postorder(BSTnode *node){   
    //goes left subtree, then right subtree, then root
    if (node != nullptr){
        display_postorder(node->left); //visits the left subtree first
        display_postorder(node->right);//after displaying all values in left subtree it moves over to the right
        cout << node->value << endl;
    }
    return 0;
}
int main(){
    BSTnode *root = nullptr;
    root = add_value(root, 50);
    add_value(root, 30);
    add_value(root, 70);
    add_value(root, 40);
    add_value(root, 20);
    add_value(root, 60);
    add_value(root, 80);
    display_inorder(root);
    //display_preorder(root);
    //display_postorder(root);
    remove_node(root, 50);
    display_inorder(root);
}