#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<int,list<int>> adj;
    map<int,int> indeg;
    for(int i = 1;i<=n;i++){
        int m;
        cin >> m;
        if(m == 0);
        for(int j = 0;j < m;j++){
            int temp;
            cin >> temp;
            adj[i].push_back(temp);
        }
    }
    for(auto i : adj)
        indeg[i.first] = 0;
    for(auto i : adj){
        for(int j : i.second)
            indeg[j] += 1;
    }
    vector<int> noindeg;
    for(auto i : adj){
        if(indeg[i.first] == 0){
            noindeg.push_back(i.first);
        }
    }
    vector<int> toposort;
    while(noindeg.size() > 0){
        int v = noindeg.back();
        toposort.push_back(v);
        noindeg.pop_back();
        for(int i : adj[v]){
            indeg[i] -= 1;
            if(indeg[i] == 0){
                noindeg.push_back(i);
            }
        }
    }
    if(toposort.size() != adj.size()){
        cout << -1;
    }
    else{
        for(int i  = toposort.size()-1;i >= 0;i--){
            cout << toposort[i] << " ";
        }
    }
}
