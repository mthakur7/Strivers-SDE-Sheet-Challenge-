/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the number of nodes in a binary tree.
*/

#include <queue>

void connectNodes(BinaryTreeNode<int> *root) {

    // Create queue and enqueue address of root in it.
    queue< BinaryTreeNode<int>* > que;
    que.push(root);

    // Number of nodes in current level.
    int nodesCount = 1;

    while(!que.empty()) {
        BinaryTreeNode<int> *previous = NULL;

        // Traversing over nodes of current level.
        while(nodesCount > 0) {
            if(previous != NULL) {
                previous->next = que.front();
            }
            previous = que.front();

            // Pushing left and right child of current node in queue. 
            if(que.front()->left != NULL) {
                que.push(que.front()->left);
            } 
            if(que.front()->right != NULL) {
                que.push(que.front()->right);
            }
            que.pop();
            nodesCount--;
        }+
        
        
        // Updating number of nodes in current level. 
        nodesCount = que.size();
    }
}
