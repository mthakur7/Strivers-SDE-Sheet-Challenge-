#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
     if(root==NULL)return;
    int c=0;
    if(root->left)
    c+=root->left->data;
    if(root->right)
    c+=root->right->data;
    if(c < root->data){
        if(root->left)root->left->data=root->data;
        if(root->right)
        root->right->data=root->data;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    changeTree(root->left);
    changeTree(root->right);
    if(root->left && root->right)root->data=root->left->data+root->right->data;
    else if(root->left)
    root->data=root->left->data;
    else if(root->right)
    root->data=root->right->data;
    else
    root->data=root->data;
}  
