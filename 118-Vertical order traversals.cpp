#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
         vector<int>ans;
         if(root==NULL) return ans;
        map<int,vector<int>>mp;
        queue<pair<TreeNode<int>*,pair<int,int>>>q;
        q.push({root,{0,0}});
  
      
        while(!q.empty()){
            TreeNode<int> * node=q.front().first;
            int idx=q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            mp[idx].push_back(node->data);               
              
            if(node->left)
            q.push({node->left,{idx-1,level+1}});
            
            if(node->right)
            q.push({node->right,{idx+1,level+1}});
       
        }
        for(auto it:mp){  
          
            ans.insert(ans.end(),it.second.begin(),it.second.end());
        }
        return ans; 
}
