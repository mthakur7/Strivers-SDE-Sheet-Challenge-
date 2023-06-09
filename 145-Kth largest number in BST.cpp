#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/


    // Write your code here.
       void fun(TreeNode<int>*root,int &k,int &ans){
        if(root==NULL)return;
        fun(root->right,k,ans);
        if(--k==0){
            ans=root->data;
        return;
    }
        fun(root->left,k,ans);
    }
    int KthLargestNumber(TreeNode<int>* root, int k) 
{
  
        //Your code here
        int ans=-1;
        fun(root,k,ans);
        if(ans==-1)
        return -1;
        return ans;
    
}
