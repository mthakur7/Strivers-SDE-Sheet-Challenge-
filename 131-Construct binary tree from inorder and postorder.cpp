/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
     TreeNode<int>* fun(vector<int>& postorder, vector<int>& inorder,int postS,int postE,int inS,int inE){
        if(postS>postE ||inS>inE)return NULL;
       
       TreeNode<int>*root=new TreeNode<int>(postorder[postE]);
         int idx=0;   
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==root->data){
            idx=i;
            break;
        }
        }
        int len=idx-inS;
        
        
       root->left= fun(postorder,inorder,postS,postS+len-1,inS,idx-1);
       root->right=fun(postorder,inorder,postS+len,postE-1,idx+1,inE);
        return root;        
    }

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
         int n=postOrder.size();
        
       TreeNode<int>*root= fun(postOrder,inOrder,0,n-1,0,n-1);
        return root;
}
