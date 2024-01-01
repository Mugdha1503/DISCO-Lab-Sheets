#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj; // Adjacency list
vector<int> parent;      // Parent nodes
vector<bool> visited;    // Visited nodes
vector<int> cycle;       // Stores the cycle
int cycleStart = -1;     // Start of the cycle
bool dfs(int v, int p) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (visited[u]) {
            // Cycle detected
            cycleStart = u;
            cycle.push_back(u);
            int cur = v;
            while (cur != u) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            return true;
        }
        parent[u] = v;
        if (dfs(u, v)) return true;
    }
    return false;
}
void findCycle(int n) {
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && dfs(i, -1)) {
            // Print the vertices of the cycle
            cout << "Cycle found: ";
            for (int j = cycle.size() - 1; j >= 0; --j) {
                cout << cycle[j] << " ";
               // if (cycle[j] == cycleStart) break;
            }
            cout << endl;
            return;
        }
    }
    // No cycle found
    cout << -1 << endl;
}
int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    findCycle(n);
    return 0;
}



