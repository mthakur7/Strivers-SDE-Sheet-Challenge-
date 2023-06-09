#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
    int next(stack<BinaryTreeNode<int>*>&nxt){
        BinaryTreeNode<int>*node=nxt.top();
        nxt.pop();
        BinaryTreeNode<int>*root=node->right;
          while(root){
            nxt.push(root);
            root=root->left;
        }
        return node->data; 
        
    }
    int before(stack<BinaryTreeNode<int>*>&bfr){
        BinaryTreeNode<int>*node=bfr.top();
        bfr.pop();
        BinaryTreeNode<int>*root=node->left;
          while(root){
            bfr.push(root);
            root=root->right;
        }
        return node->data; 
        
    }
  
   
    
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
         stack<BinaryTreeNode<int>*>nxt;
        stack<BinaryTreeNode<int>*>bfr;
        BinaryTreeNode<int>*node=root;
        while(node){
            nxt.push(node);
            node=node->left;
        }
        node=root;
          while(node){
            bfr.push(node);
            node=node->right;
        }
           int i=next(nxt);
            int j=before(bfr);
        
        while(i<j){        
            
            if(i+j == k)
                return true;
            else if(i+j>k)
                j=before(bfr);
            
            else
                i=next(nxt);
                
        }
        return false;
}
