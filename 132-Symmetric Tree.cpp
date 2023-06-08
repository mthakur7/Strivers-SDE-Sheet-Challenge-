/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

    bool fun(BinaryTreeNode<int>*r1,BinaryTreeNode<int>*r2){
        if(r1==NULL && r2==NULL)return true;
        if(r1 && !r2 || !r1 && r2)return false;
        if(r1->data ==r2->data && fun(r1->left,r2->right) && fun(r1->right,r2->left))
             return true;
        return false;
    }
    bool isSymmetric(BinaryTreeNode<int>* root) {
       if(!root)return true;
        return fun(root->left,root->right);
    }
