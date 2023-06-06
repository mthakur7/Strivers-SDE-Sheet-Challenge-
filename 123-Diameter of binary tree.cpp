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
 int mxHeight(TreeNode<int>*root, int &diameter){
        if(root==NULL)
            return 0;
        
        int lh=mxHeight(root->left,diameter);
        int rh=mxHeight(root->right,diameter);
        
       
        diameter=max(lh+rh,diameter);
        
        return max(lh,rh)+1;
    }

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int diameter=0;
       mxHeight(root,diameter);     
       return diameter;
}
