#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
    bool fun(TreeNode<int> *root, int x,vector<TreeNode<int>*>&ans){
	if(root==NULL)return false;
  if (root->data == x) {
    ans.push_back(root);
    return true;
  }
        if (fun(root->left, x, ans)) {
			ans.push_back(root);
          return true;
        } else if (fun(root->right, x, ans)) {
			ans.push_back(root);
          return true;
        } else
          return false;
}

int lowestCommonAncestor(TreeNode<int> *root, int p, int q)
{
	//    Write your code here
       vector<TreeNode<int>*>vec1;
        vector<TreeNode<int>*>vec2;
        fun(root,p,vec1);
        fun(root,q,vec2);
        
        int i=vec1.size()-1,j=vec2.size()-1;
        while(i>=0 && j>=0 && vec1[i]==vec2[j] ){
            i--;
            j--;
        }
        return vec1[i+1]->data;
    }
