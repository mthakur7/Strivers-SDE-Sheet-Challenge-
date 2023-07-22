#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
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

*************************************************************/
  /*
    Time Complexity : O(N)
    Space Complexity : O(N).

    Where N denotes number of nodes in the binary tree
*/

bool helper(BinaryTreeNode<int>* root, int min, int max) {

    // An empty tree is a BST
    if (root == NULL) {
        return true;
    }

    // False if this node violates the min/max constraint
    if ((root->data < min) || (root->data > max)) {
        return false;
    }

    // Otherwise check the subtrees recursively, modifying the min or max constraint
    bool leftSearch = helper(root->left, min, root->data);
    bool rightSearch = helper(root->right, root->data, max);

    return leftSearch & rightSearch;
}

bool validateBST(BinaryTreeNode<int>* root) {
    return (helper(root, INT_MIN, INT_MAX));
}
