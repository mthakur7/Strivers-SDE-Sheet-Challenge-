/*
    Time complexity: O(E*log(V))
    Space complexity: O(V^2)

    Where 'E' is the number of edges and 'V' is
    the number of vertices in a graph.
*/

vector<int> dijkstraHelper(vector<vector<pair<int, int>>> &adjacencyList, int vertices, int source) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(vertices, INT_MAX);

    // Push the source vertex in the priority queue.
    pq.push({0, source});

    // Distance of a vertex to itself is 0.
    distance[source] = 0;
    vector<bool> visited(vertices, false);

    // Loop till all vertices are visited.
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        // Update the distances of the adjacent nodes.
        for (auto it = adjacencyList[u].begin(); it != adjacencyList[u].end(); it++) {
            int v = it -> first;
            int dist = it -> second;

            if (visited[v] == false && distance[v] > distance[u] + dist) {
                distance[v] = distance[u] + dist;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    vector<vector<pair<int, int>>> adjacencyList(vertices);

    // Create an adjacency list.
    for (int i = 0; i < (int)vec.size(); i++) {
        
        adjacencyList[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        adjacencyList[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    return dijkstraHelper(adjacencyList, vertices, 0);
}
