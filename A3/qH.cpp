#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool areIsomorphic(const vector<pair<int, int>>& edges1, const vector<pair<int, int>>& edges2) {
    if (edges1.size() != edges2.size()) 
        return false;
    vector<int> degrees1(10, 0); // Max nodes assumed as 10, you may increase this as per your input size
    vector<int> degrees2(10, 0);
    for (const auto& edge : edges1) {
        degrees1[edge.first]++;
        degrees1[edge.second]++;
    }
    for (const auto& edge : edges2) {
        degrees2[edge.first]++;
        degrees2[edge.second]++;
    }
    sort(degrees1.begin(), degrees1.end());
    sort(degrees2.begin(), degrees2.end());
    return degrees1 == degrees2;
}
int main() {
    int n1, m1;
    cin >> n1 >> m1;
    vector<pair<int, int>> edges1;
    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        edges1.emplace_back(u, v);
    }
    int n2, m2;
    cin >> n2 >> m2;
    vector<pair<int, int>> edges2;
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        edges2.emplace_back(u, v);
    }
    if (areIsomorphic(edges1, edges2)) 
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}








