//euler tour
//template problem: https://mcpt.ca/problem/treedistance
#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;
const int LOG = 17;
vector<int> adj [MN];
int N,Q,par[MN][LOG], depth [MN];
void dfs(int u, int p){
    for(int i : adj[u]){
        if(i != p){
            par[i][0]=u; 
            depth[i] = depth[u]+1;
            dfs(i,u);
        }
    }
}
void build(){
    for(int i = 1; i < LOG; i++)
		for(int j = 1; j <= N; j++)
			if(par[j][i - 1] != -1)
				par[j][i] = par[par[j][i - 1]][i - 1];

}
int LCA(int a,int b){
    if(depth[a] > depth[b]) swap(a, b);
	for(int i = LOG - 1; i >= 0; i--)
		if(depth[b] - (1 << i) >= depth[a])
			b = par[b][i];

	if(a == b) return a;

	for(int i = LOG - 1; i >= 0; i--)
		if(par[a][i] != par[b][i])
			a = par[a][i], b = par[b][i];

	return par[b][0];
}

int main() {
    scanf("%d%d", &N, &Q);
    for(int i = 1,u,v;i<N;i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(par,-1,sizeof(par));
    dfs(1,-1);
    //build();
    for(int i = 1; i < LOG; i++)
		for(int j = 1; j <= N; j++)
			if(par[j][i - 1] != -1)
				par[j][i] = par[par[j][i - 1]][i - 1];
    for(int i = 0,u,v;i<Q;i++){
        scanf("%d%d",&u,&v);
        printf("%d\n", depth[u] + depth[v] - 2 * depth[LCA(u,v)]);
    }
}