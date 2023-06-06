#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/
bool fun(TreeNode<int> *root, int x,vector<int>&ans){
	if(root==NULL)return false;
  if (root->data == x) {
    ans.push_back(root->data);
    return true;
  }
        if (fun(root->left, x, ans)) {
			ans.push_back(root->data);
          return true;
        } else if (fun(root->right, x, ans)) {
			ans.push_back(root->data);
          return true;
        } else
          return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>ans;
    fun(root,x,ans);
	reverse(ans.begin(),ans.end());
	return ans;
}
