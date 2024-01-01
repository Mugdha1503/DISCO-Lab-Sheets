#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node, vector<vector<int>>& edges, vector<int>& visited, vector<int>& path) {
    visited[node] = 1;
    path.push_back(node);
    for (int neighbor : edges[node]) {
        if (visited[neighbor] == 0) {
            if (dfs(neighbor, edges, visited, path))
                return true;
        }
        else if (visited[neighbor] == 1) {
            // Cycle detected
            int start = 0;
            while (path[start] != neighbor) {
                start++;
            }
            for (int i = start; i < path.size(); ++i) {
                cout << path[i] << " ";
            }
            cout << endl;
            return true;
        }
    }
    visited[node] = 2;
    path.pop_back();
    return false;
}
void findCycle(int n, vector<vector<int>>& edges) {
    vector<int> visited(n + 1, 0);
    vector<int> path;
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            if (dfs(i, edges, visited, path))
                return;
        }
    }
    cout << "-1" << endl;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    findCycle(n, edges);
    return 0;
}



