/*
    Time Complexity: O((n * k) * (log(n * k)))
    Space complexity: O(n * k)

    Where ‘n’ denotes the size of the linked list and ‘k’ is the average number of child nodes for each of the n nodes. 
*/

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

#include<algorithm>

Node* flattenLinkedList(Node* root) 
{
	vector<int> answer ;

	// Traverse the linkedlist and add all the nodes to the array
	while (root != NULL) 
	{
		answer.push_back(root->data);
		Node *temp = root;

		// Add all child nodes
		while (temp->child != NULL) 
		{
			answer.push_back(temp->child->data);
			temp = temp->child;
		}
		root = root->next;
	}

	sort(answer.begin(), answer.end());

	Node *head = NULL;
	Node *tail = NULL;

	// Create new linked list
	for (int i = 0; i < answer.size(); ++i) 
	{
		Node *newNode = new Node(answer[i]);
		if (head == NULL) 
		{
			head = newNode;
		} 
		else 
		{
			tail->child = newNode;
		}
		tail = newNode;
	}
	return head;
}
