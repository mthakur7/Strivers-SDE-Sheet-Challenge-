/* 
	Time complexity: O(V + E). 
	Space complexity: O(V^2). 

	Where V is the number of vertices in the input graph and 
    E is the number of edges in the input graph.
*/

#include <queue>


// Converts the given input into adjacency matrix. 

vector<int> BFS(int vertex, vector<pair<int, int>> &edges)
{

	vector<int> adjacency_matrix[vertex];


	for (int i = 0; i < edges.size(); i++)
	{

		adjacency_matrix[edges[i].first].push_back(edges[i].second);
		adjacency_matrix[edges[i].second].push_back(edges[i].first);
	}
	
	vector<bool> visited(vertex);

	for(int i =0; i<vertex; i++){
        visited[i] = false;
    }
	vector<int> result;
	// Traversing through all the nodes.
	for (int i = 0; i < vertex; i++)
	{
		if (!visited[i])
		{
				queue<int> queue;
	visited[i] = true;
	queue.push(i);

	// Traversing all the nodes that are connected to the source node.
	while (!queue.empty())
	{
		int front = queue.front();
		queue.pop();
		result.push_back(front);

		
	
			for (auto x:adjacency_matrix[front])
			{
                          if (!visited[x]) {
                            visited[x] = true;
                            queue.push(x);
                          }
                        }
		
	}
		}
	}

	return result;

}
