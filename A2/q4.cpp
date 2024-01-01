#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
int vis[N];
int level[N];
void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int cur_node=q.front();
        q.pop();
        for(int child:g[cur_node]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_node]+1;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    cout<<level[n];
    return 0;
}

