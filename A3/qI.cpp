#include <iostream>
#include <vector>
using namespace std;
bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfsCheck(it, adj, vis, pathVis, check)) return true;
        } else if (pathVis[it]) return true;
    }
    pathVis[node] = 0;
    check[node] = 1; 
    return false;
}
vector<int> safeNodes(int v, vector<int> adj[]) {
    int vis[v + 1] = {0}; 
    int pathVis[v + 1] = {0}; 
    int check[v + 1] = {0}; 
    vector<int> safenodes;
    for (int i = 1; i <= v; i++) {
        if (!vis[i] && dfsCheck(i, adj, vis, pathVis, check)) 
            check[i] = 0;
    }
    for (int i = 1; i <= v; i++) {
        if (check[i] == 1) safenodes.push_back(i);
    }
    return safenodes;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> answer = safeNodes(n, adj);
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    return 0;
}


