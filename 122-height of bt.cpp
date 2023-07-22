/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the total number of nodes in the binary tree.
*/


typedef struct Node{

	// Height stores the height of the current subtree.
	int height;
	int leftIndex;
	int rightIndex;
} 
Node;

#include <queue>

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	queue<Node> q;
	Node init;

	init.height = 0;
	init.leftIndex = 0;
	init.rightIndex = N - 1;

	q.push(init);
      
	int pos[N+1];

	for(int i = 0; i < N; i++){
		pos[inorder[i]] = i;
	}

	int maxHeight = 0;

	for(int i = 0; i < N; i++){
		int curr = levelOrder[i];

		Node now = q.front();

		q.pop();

		// Position of levelOrder[i] in the inorder array. 
		int currPos = pos[levelOrder[i]];
		
		// There is a left child present.
		if(currPos > now.leftIndex){
			Node newNode;

			// Height will increase by 1 as we are descending 1 level downwards in the tree.
			newNode.height = now.height + 1;

			maxHeight = max(maxHeight, newNode.height);

			// New borders of the left subtree in the inorder array.
			newNode.leftIndex = now.leftIndex;
			newNode.rightIndex = currPos - 1;

			q.push(newNode);
		}

		// There is a right child present.
		if(currPos < now.rightIndex){
			Node newNode;
			newNode.height = now.height + 1;
			maxHeight = max(maxHeight, newNode.height);

			// New borders of the right subtree in the inorder array.
			newNode.leftIndex = currPos + 1;
			newNode.rightIndex = now.rightIndex;

			q.push(newNode);
		}
	}

	return maxHeight;
}
