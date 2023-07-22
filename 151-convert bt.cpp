/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    where 'N' is the number of nodes in the tree.
*/

/*************************************************************
 
        Following is the Binary Tree node structure

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
        };

*************************************************************/

void findHead(BinaryTreeNode<int> *root, BinaryTreeNode<int> **head, BinaryTreeNode<int> **prev) {
    
    // Base case.
    if(root == NULL)
    {
        return ;
    }

    findHead(root->left, head, prev);

    if(*prev == NULL)
    {
        *head = root;
    }
    else
    {
        root->left = *prev;
        (*prev)->right = root;
    }

    *prev = root;

    findHead(root->right, head, prev);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* head = NULL;
    BinaryTreeNode<int>* prev = NULL;
    findHead(root, &head, &prev);

    return head;
}
