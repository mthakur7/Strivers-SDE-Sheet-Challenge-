#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
bool isLeaf(TreeNode<int>*root){
   if(!root->left && !root->right)
       return 1;
    else
     return 0;
   
}

void fun(TreeNode<int>* root,vector<int>&bottom){

if(isLeaf(root)){
bottom.push_back(root->data);
return;
}

if(root->left)fun(root->left,bottom);
if(root->right)fun(root->right,bottom);

}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.   
     vector<int>ans;
     if(root==NULL)return ans;
     if(!isLeaf(root))ans.push_back(root->data);

     TreeNode<int>*curr=root->left;
     while(curr){
         if(!isLeaf(curr))
         ans.push_back(curr->data);
         if(curr->left)
         curr=curr->left;
         else
         curr=curr->right;
     }
  vector<int>bottom;
  fun(root,bottom);
  for(int i=0;i<bottom.size();i++)
  ans.push_back(bottom[i]);

      curr=root->right;
      vector<int>r;
     while(curr){
         if(!isLeaf(curr))
         r.push_back(curr->data);
         if(curr->right)
         curr=curr->right;
         else
         curr=curr->left;
     }
     for(int i=r.size()-1;i>=0;i--)
     ans.push_back(r[i]);
     
return ans;

}
