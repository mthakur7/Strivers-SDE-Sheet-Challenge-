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
   TreeNode<int>* fun(vector<int>& preorder, vector<int>& inorder,int preS,int preE,int inS,int inE){
        if(preS>preE ||inS>inE)return NULL;
       
       TreeNode<int>*root=new TreeNode<int>(preorder[preS]);
         int idx=0;   
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==root->data){
            idx=i;
            break;
        }
        }
        int len=idx-inS;
        
        
       root->left= fun(preorder,inorder,preS+1,preE,inS,idx-1);
       root->right=fun(preorder,inorder,preS+len+1,preE,idx+1,inE);
        return root;        
    }

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
       int n=preorder.size();
        
       TreeNode<int>*root= fun(preorder,inorder,0,n-1,0,n-1);
        return root;
}
