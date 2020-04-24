#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;
int N, M, start,ending;
vector<int> adj[MN];
bool vis[MN];
int main() {
    memset(vis,false,sizeof(vis));
    scanf("%d %d", &N, &M);
    for(int i = 0,u,v;i<M;i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d %d", &start, &ending);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(!q.empty()){
        int u = q.front();q.pop();
        if(u==ending){
            cout<<"found\n";
            return 0;
        }
        for(int v : adj[u]){
            if(!vis[v])q.push(v),vis[v]=true;
        }
    }
    cout<<"not found\n";
}