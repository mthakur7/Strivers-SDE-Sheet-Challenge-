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
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
       stack<TreeNode*>st;
        vector<int>ans;
        while(true){
        if(root!=NULL){
            ans.push_back(root->data);
            st.push(root);
            root=root->left;
        }
        else{
            if(st.empty())break;
            root=st.top();
            st.pop();
            root=root->right;
        }
                   
        }
        return ans;
}
