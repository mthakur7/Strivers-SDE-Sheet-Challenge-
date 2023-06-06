#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
           if(!root) return 0;
        queue<pair<TreeNode<int>*,int>>q;
        q.push({root,0});
        int ans=0;
        
        while(!q.empty()){
          
            int x=q.size();
          
            vector<int>v;
            for(int i=0;i<x;i++){
            TreeNode<int>* node=q.front().first;
             int idx=q.front().second; 
              
            q.pop();
            v.push_back(idx);
                
            if(node->left)
            q.push({node->left,idx-1});
            
            if(node->right)
            q.push({node->right,idx+1});
           
            }
        
           int s=v.size();
            ans=max(ans,s);
     
         
        
        }
        return ans; 
}
