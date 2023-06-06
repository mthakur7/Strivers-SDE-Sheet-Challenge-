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
int height(BinaryTreeNode<int>* root,bool &bal){
    if(root==NULL)return 0;
   int lh= height(root->left,bal);
   int rh= height(root->right,bal);

   if(abs(lh-rh)>1)
   bal=false;
  
   return max(lh,rh)+1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    bool bal=true;
    height(root,bal);
    return bal;
}
