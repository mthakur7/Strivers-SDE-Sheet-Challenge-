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

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
            stack<TreeNode<int>*>st;
        int ans=0;
        int count=0;
        while(true){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                if(st.empty())break;
                root=st.top();
                st.pop();
                count++;
                if(count==k){
                    ans=root->data;
                break;
            }
                root=root->right;
            }
        }
        return ans;
}
