/*
    Time Complexity: O(M * log(M) + N + M)
    Space Complexity: O(N + M)

    Where 'N' and 'M' denotes the number of nodes and edges in the graph, respectively.
*/

#include <algorithm>

// Creates a new set consisting of the new element v.
void make_set(int v, vector <int> &parent, vector <int> &rank) {
    parent[v] = v;
    rank[v] = 0;
}

// Returns the parent of the set that contains the element v.
int find_set(int v, vector <int> &parent) {
    if (v == parent[v]) {
        // Current element is the parent of its set.
        return v;
    } else {
        // Using path compression technique.
        return parent[v] = find_set(parent[v], parent);
    }
}

// Merges the two specified sets.
void union_sets(int a, int b, vector <int> &parent, vector <int> &rank) {
    // Find the parent of both elements.
    a = find_set(a, parent);
    b = find_set(b, parent);

    if (a != b) {
        if (rank[a] < rank[b]) {
        	// Swap.
            swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}

// Custom comparator to sort the edges.
bool compare(vector <int> const &a, vector <int> const &b) {
    return a[2] < b[2];
}

int kruskalMST(int n, int m, vector <vector<int> > &graph) {
    // Parent and rank arrays to be used in DSU.
    vector <int> parent(n);
    vector <int> rank(n);

    for (int i = 1; i <= n; i++) {
        // Create a new set for each node.
        make_set(i, parent, rank);
    }

    // To store the weight of MST.
    int cost = 0;

    // Sort the edges in ascending order by its weight.
    sort(graph.begin(), graph.end(), compare);

    // Start traversign through the edges.
    for (auto edge: graph) {
        // Check if both vertices of current edge belong to different sets(subtrees).
        if (find_set(edge[0], parent) != find_set(edge[1], parent)) {
            // Add the weight of the current edge.
            cost = cost + edge[2];

            // Merge the two sets(subtrees).
            union_sets(edge[0], edge[1], parent, rank);
        }
    }
    return cost;
}
