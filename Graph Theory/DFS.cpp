#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;
int N, M, start,ending;
vector<int> adj[MN];
bool vis[MN];
void dfs(int u){
    for(int v : adj[u]){
        if(!vis[v]){
            vis[v] = true;
            dfs(v);
        }
    }
    return;
}
int main() {
    memset(vis,false,sizeof(vis));
    scanf("%d %d", &N, &M);
    for(int i = 0,u,v;i<M;i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d %d", &start, &ending);
    vis[start]= true;
    dfs(start);
    if(vis[ending])cout<<"found\n";
    else cout<<"not found\n";
}