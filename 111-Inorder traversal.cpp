#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
      
        stack<TreeNode*>st;
        vector<int>ans;
        while(true){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }
            else{
                if(!st.empty()){
                root=st.top();
                ans.push_back(root->data);
                st.pop();
                root=root->right;
                }
                else
                    break;
            }
        }
        return ans;
    
}
