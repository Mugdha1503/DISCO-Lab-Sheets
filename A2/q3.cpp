#include <iostream>
#include <vector>
using namespace std;
void printPath(const vector<int>& path) {
    for (int vertex : path) {
        cout << vertex << " ";
    }
}
void DFS(const vector<vector<int>>& tree, 
        vector<bool>& visited, 
        vector<int>& path, 
        int current, int destination) {
    visited[current] = true;
    path.push_back(current);
    if (current == destination) {
        cout << path.size() << endl;
        printPath(path);
        return;
    }
    for (int neighbor : tree[current]) {
        if (!visited[neighbor]) {
            DFS(tree, visited, path, neighbor, destination);
        }
    }
    path.pop_back();
}
int main() {
    int n; 
    cin >> n;
    vector<vector<int>> tree(n + 1); 
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int u, v; 
    cin >> u >>v;
    vector<bool> visited(n + 1);
    vector<int> path;
    DFS(tree, visited, path, u, v);
}

