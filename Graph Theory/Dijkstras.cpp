#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
const int MN = 301;
int N,M,T;
int d [MN][MN];
vector<pii> adj[MN];
void djikstras(int s){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[s][s] = 0;
    pq.push({s,0});
    while (!pq.empty()){
        int node = pq.top().first;pq.pop();
        for(pii i : adj[node]){
            int newnode = i.first, value = i.second;
            if(max(d[s][node],value) < d[s][newnode] || d[s][newnode]==-1){
                d[s][newnode] = max(d[s][node],value);
                pq.push({newnode,d[s][newnode]});
            }
        }
    }
}
int main(){
    memset(d, -1, sizeof (d));
    cin>>N>>M>>T;
    for(int i = 0,a,b,v;i<M;i++){
        cin>>a>>b>>v;
        adj[a].push_back({b,v});
    }
    //for every node, see shortest path from said node to all other nodes
    for(int i = 1;i<=N;i++)djikstras(i);
    for(int i = 0,a,b;i<T;i++){
        cin>>a>>b;
        cout<<d[a][b]<<'\n';
    }
    return 0;
}
