#include <iostream>
#include <vector>
using namespace std;

bool isBipartiteUtil(vector<vector<int>>& graph, 
                    vector<int>& color, 
                    int vertex, int currentColor) {
    color[vertex] = currentColor;
    for (int neighbor : graph[vertex]) {
        if (color[neighbor] == -1) {
            // Neighbor not colored, recursively check if it's bipartite
            if (!isBipartiteUtil(graph, color, neighbor, 1 - currentColor)) {
                return false;
            }
        } else if (color[neighbor] == currentColor) {
            // Neighbor has the same color, the graph is not bipartite
            return false;
        }
        // If the neighbor has a different color, continue to the next neighbor
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph, int n) {
    vector<int> color(n + 1, -1);
    // Check each component of the graph (in case it's not connected)
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1 && !isBipartiteUtil(graph, color, i, 0)) {
            return false; // Graph is not bipartite
        }
    }
    return true; // Graph is bipartite
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << ( isBipartite(graph, n) ? "YES" : "NO" );
}

