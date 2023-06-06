#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void traverse(BinaryTreeNode<int> *root,vector<int>&ino,vector<int>&pre,vector<int>&post){
if(root==NULL)return;
pre.push_back(root->data);
traverse(root->left,ino,pre,post);
ino.push_back(root->data);
traverse(root->right,ino,pre,post);
post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int>ino;
    vector<int>pre;
    vector<int>post;
    vector<vector<int>>ans;
    traverse(root,pre,ino,post);
  
    ans.push_back(pre);
    ans.push_back(ino);
    ans.push_back(post);
    return ans;
}
