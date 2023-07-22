#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
       vector<int>ans;
    if(!root)
        return ans;
    map<int,int>mp;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        TreeNode<int>*node=q.front().first;
        int x=q.front().second;
        q.pop();
        
        if(node->left)
            q.push({node->left,x-1});
        if(node->right)
            q.push({node->right,x+1});
      if(mp.find(x)==mp.end())
        mp[x]=node->val;
        
    }
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}
