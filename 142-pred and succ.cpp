#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
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
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

   
    
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* node, int key)
{
    // Write your code here.
    BinaryTreeNode<int>*root=node;
    int succ=-1;
    while (root) {
      if (root->data > key){
        succ = root->data;
      root = root->left;
    }
         else if(root->data<=key)
         root=root->right;
 }


     root=node;
       int pre=-1;
    while (root) {
      if (root->data >= key){      
      root = root->left;
      } else if (root->data < key) {
        pre = root->data;
         root = root->right;
         }

     }
     return {pre,succ};
}
