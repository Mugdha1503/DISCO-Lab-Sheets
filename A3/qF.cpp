#include <iostream>
#include<vector>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
int depth[N];
void dfs(int node, int par=0){
    for(int child:g[node]){
        if(child==par) continue;
        depth[child]=depth[node]+1;
        dfs(child,node);
    }
}
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n-1;i++){
       int x,y;
       cin>>x>>y;
       g[x].push_back(y);
       g[y].push_back(x);
   }
    dfs(1); 
    int max_depth=-1,max_d_node;
    for(int i=1;i<=n;i++){
        if(depth[i]>max_depth){
            max_depth=depth[i];
            max_d_node=i;
        }
        depth[i]=0;
    }
    dfs(max_d_node);
    int mx_depth=-1;
    for(int i=1;i<=n;i++){
        if(depth[i]>mx_depth){
            mx_depth=depth[i];
        }
    }
    cout<<mx_depth;
    return 0;
}

