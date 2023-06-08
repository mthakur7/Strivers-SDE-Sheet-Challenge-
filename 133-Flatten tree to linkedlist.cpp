#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
  TreeNode<int>*fun(TreeNode<int>*root){
        if(root==NULL)return NULL;
     TreeNode<int>*left=fun(root->left);
     TreeNode<int>*right=fun(root->right);
     TreeNode<int>*temp=left;
        if(root->left){
        while(temp->right){
            temp=temp->right;
        }
        temp->right=right;
        root->right=left;
        root->left=NULL;
        }
   return root;
    }
   
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{ return fun(root);
}
