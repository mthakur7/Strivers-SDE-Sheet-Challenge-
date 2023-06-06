#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){
   vector<int>ans;
    if(!root)
        return ans;
    map<int,int>mp;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        BinaryTreeNode<int>*node=q.front().first;
        int x=q.front().second;
        q.pop();
        
        if(node->left)
            q.push({node->left,x-1});
        if(node->right)
            q.push({node->right,x+1});
      
        mp[x]=node->data;
        
    }
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}
