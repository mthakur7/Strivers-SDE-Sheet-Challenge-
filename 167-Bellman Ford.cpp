#include <bits/stdc++.h> 
int bellmonFord(int V, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(V+1, 1e9);
		dist[src] = 0;
		for (int i = 0; i < V ; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}

    
		return dist[dest];
}
