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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
          vector<int>ans;
          if(root==NULL) return ans;
        queue<BinaryTreeNode<int> *>q;
        q.push(root);
         int count=0;
         int idx=0;
        while(!q.empty()){
           
            int x=q.size();
            count++;
            vector<int>v(x);
            for(int i=0;i<x;i++){
            BinaryTreeNode<int> * node=q.front();
            q.pop();
            int idx=count%2==1?i:x-i-1;   
            v[idx]=node->data;
                
            if(node->left)
            q.push(node->left);
            
            if(node->right)
            q.push(node->right);

              idx++;  
            }
            for(int i=0;i<v.size();i++)
            ans.push_back(v[i]);
        
         
                
           
        }
        return ans; 
}
