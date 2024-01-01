#include <stdio.h>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,int>> edges;
    vector<int> key(n+1),parent(n+1);
    vector<bool> mst(n+1);
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    edges.push_back({{u,v},wt});
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
    }
    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }
    //algorithm starts
    key[1]=0;
    parent[1]=-1;
    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }
        mst[u]=true;
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false&&w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }
    int total_cost=0;
    for(int i=1;i<=n;i++){
       total_cost+= key[i];
    }
    cout<<total_cost<<endl;
    return 0;
}


