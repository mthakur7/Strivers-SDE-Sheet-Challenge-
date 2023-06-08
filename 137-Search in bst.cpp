#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
       while(root!=NULL && root->data!=x){
         if(root->data>x)
             root=root->left;
         else if(root->data<x)
             root=root->right;
     }
     if(root)
     return true;
     else
     return false;
       
    
}
