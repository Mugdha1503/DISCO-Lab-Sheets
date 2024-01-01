#include <bits/stdc++.h>
using namespace std;
void DFS(map<int,bool> visited, map <int,list<int>> adj, int v,vector<int> &dfs_v)
{
    visited[v] = true;
    dfs_v.push_back(v);
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(visited,adj,*i,dfs_v);
}
void DFSr(map<int,bool> visited, map <int,list<int>> adjr, int v,vector <int> &dfs_vr)
{
    visited[v] = true;
    dfs_vr.push_back(v);

    list<int>::iterator i;
    for (i = adjr[v].begin(); i != adjr[v].end(); ++i)
        if (!visited[*i])
            DFSr(visited,adjr,*i,dfs_vr);
}
int main(){
    map <int,bool> visited;
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    map <int,list<int>> adj;
    map <int,list<int>> adjr;
    for(int i = 0;i<m;i++){
        int v,v1;
        cin >> v >> v1;
        adj[v].push_back(v1);
        adjr[v1].push_back(v);
    }
    vector<int> dfs_x,dfs_y,dfs_xr,dfs_yr;
    DFS(visited,adj,x,dfs_x);
    DFS(visited,adj,y,dfs_y);

    DFSr(visited,adjr,x,dfs_xr);
    DFSr(visited,adjr,y,dfs_yr);
    for(int i: dfs_xr){
        int flag = 0;
        for(int j : dfs_yr){
            if(i == j){
                cout << i << " ";
                flag = 1;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    for(int i: dfs_x){
        int flag = 0;
        for(int j : dfs_y){
            if(i == j){
                cout << i;
                flag = 1;
                break;
            }
        }
        if(flag){
            break;
        }
    }
}

