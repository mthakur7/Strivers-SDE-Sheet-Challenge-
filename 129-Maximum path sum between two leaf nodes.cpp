#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
 long long int fun(TreeNode<int>*root,long long int &sum){
        if(root==NULL)return 0;
       
       long long int ls= fun(root->left,sum);
       long long int rs=fun(root->right,sum);
        
        sum=max(sum,ls+rs+(long long int)root->val);        
        
        return max(ls,rs)+(long long int)root->val;
    }

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here
    if(!root ||!root->left || !root->right) return -1;
      long long int sum=INT_MIN;
        fun(root,sum);
        return sum;
}
