#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
int answer=-1;
void dfs(int node, int edges[], unordered_map<int,int> &dist,vector<bool> &visit){
    visit[node]=true;
    int neighbour = edges[node];
    if(neighbour!=0 && !visit[neighbour]){
        dist[neighbour]=dist[node]+1;
        dfs(neighbour,edges,dist,visit);
    }
    else if(neighbour!=0 && dist.count(neighbour)){
        answer=max(answer,dist[node]-dist[neighbour]+1);
    }
}
int longestCycle(int edges[],int n){
    vector<bool> visit(n);
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            unordered_map<int,int> dist;
            dist[i]=1;
            dfs(i,edges,dist,visit);
        }
    }
    return answer;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int edges[m]={0};
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        edges[x]=y;
    }
    cout<<longestCycle(edges,n)<<endl;
    return 0;
}




