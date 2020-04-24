//JOI '14 Factories
//#include "factories.h"
//idea of centroid decomposition is to decompose the tree into logN layers to turn querying into NlogN rather than potentially N^2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 5e5+6, LOG = 19;
const ll INF = 1e18;
int N, sz[MN], lvl[MN], pa[MN]; ll dist [LOG][MN], tmp[MN], ans; 
std::vector <pii> adj[MN];
bool done[MN]; 
//checks the size of subtrees
void getsz(int u, int prev){
    sz[u] = 1;
    for(pii e : adj[u]){
        if(e.first != prev && !done[e.first]){
            getsz(e.first,u);
            sz[u]+=sz[e.first];
        }
    }
}
//returns centroid
//2*sz[e.first]>tot ensures that if one subtree has more than half the nodes, the centroid must be there
int getCent(int u, int prev, int tot){
    for(pii e : adj[u]){
        if(e.first != prev && !done[e.first] && 2*sz[e.first]>tot){
            return getCent(e.first,u,tot);
        }
    }
    return u;
}
//construction of centroid tree
void dfs(int u, int prev, int lvl, ll d){
    dist[lvl][u] = d;//update centroid tree
    for(pii e : adj[u]){
        if(e.first != prev && !done[e.first]){
            dfs(e.first,u,lvl,d+e.second);//next layer of dfs
        }
    }
}
//root, parent, and level
void solve(int rt, int pre, int level){
    getsz(rt,-1);
    rt = getCent(rt,-1,sz[rt]);
    //centroid decomposition template
    done[rt]=true;//block off centroid
    lvl[rt] = level;//level of node
    pa[rt] = pre;
    dfs(rt, -1, level, 0);
    for(pii e : adj[rt]){
        if(!done[e.first])solve(e.first,rt,level+1);//next layer of centroid decomposition
    }
}
//template intiallization
void Init(int n, int A[], int B[], int D[]){
    N = n;memset(tmp,0x3f,sizeof(tmp));
    //intiallize adjacency list
    for(int i = 0;i<N-1;i++){
        adj[A[i]].push_back({B[i],D[i]});
        adj[B[i]].push_back({A[i],D[i]});
    }
    solve(1,-1,0);
}
long long Query(int S, int X[], int T, int Y[]){
    ans = INF;
    //updating temp with info from centroid tree
    for(int i = 0;i<S;i++){
        for(int u = X[i],v = X[i],cnt = lvl[u];u!=-1;u = pa[u],cnt--){
            tmp[u] = min(tmp[u],dist[cnt][v]);
        }
    }
    //querying for answer
    for(int i = 0;i<T;i++){
        for(int u = Y[i],v = Y[i],cnt = lvl[u];u!=-1;u = pa[u],cnt--){
            ans = min(ans, tmp[u] + dist[cnt][v]);
        }
    }
    //reset the array, memset is too slow
    for(int i = 0;i<S;i++){
        for(int u = X[i];u!=-1;u = pa[u]){
            tmp[u] = INF;
        }
    }
    return ans;
}
int main() {

    return 0;
}
