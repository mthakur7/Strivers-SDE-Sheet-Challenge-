#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int val)
{
    // Write your code here.
       int floor=-1;
    while (root != NULL) {
      if (root->val == val) {
        floor = root->val;
        return floor;
      }

      if (root->val > val) {        
        root = root->left;       
      } else{
          floor=root->val;
        root = root->right;
      }
     }
        return floor;
}
