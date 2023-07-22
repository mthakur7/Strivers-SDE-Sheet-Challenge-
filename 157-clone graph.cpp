/*
    Time Complexity: O(N + M)
    Space Complexity: O(N)

    Where N is the number of nodes
    and M is the number of edges in the given graph.
*/

#include <unordered_map>

graphNode *cloneGraphHelper(graphNode *node, unordered_map<graphNode *, graphNode *> &copies)
{
	// If the current node is NULL.
	if (node == NULL)
	{
		return NULL;
	}

	// If HashMap doesn't contain the node.
	if (copies.find(node) == copies.end())
	{
		copies[node] = new graphNode(node->data, {});

		// Go through all the neighbours.
		for (graphNode *neighbour : node->neighbours)
		{
			copies[node]->neighbours.push_back(cloneGraphHelper(neighbour, copies));
		}
	}

	return copies[node];
}

graphNode *cloneGraph(graphNode *node)
{
	// Create a HashMap.
	unordered_map<graphNode *, graphNode *> copies;

	// Return the source node of cloned graph.
	return cloneGraphHelper(node, copies);
}
