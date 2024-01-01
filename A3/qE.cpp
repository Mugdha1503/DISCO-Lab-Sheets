#include <iostream>
#include<vector>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
int height[N];
void dfs(int node, int par=0){
    for(int child:g[node]){
        if(child==par) continue;
        dfs(child,node);
        height[node]=max(height[node],height[child]+1);
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
    cout<<height[1];
    return 0;
}


