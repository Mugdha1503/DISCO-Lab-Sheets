#include <iostream>
#include <vector>
using namespace std;
bool isValidColoring(const vector<int>& colors, const vector<vector<int>>& graph) {
    for (int node = 0; node < graph.size(); ++node) {
        for (int neighbor : graph[node]) {
            if (colors[node] == colors[neighbor]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    isValidColoring(colors, graph) ? cout << "YES" : cout << "NO";
}

