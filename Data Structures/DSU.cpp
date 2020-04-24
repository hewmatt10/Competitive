//https://dmoj.ca/problem/ds2
//disjoint set
#include <bits/stdc++.h>
using namespace std;
int parent[1000001];
set<int> st;
int find(int x) {
    if(parent[x]==-1) return x;
    parent[x]=find(parent[x]);
    return parent[x];
}
int main() {
    int N,M; cin>>N>>M;
    memset(parent,-1,sizeof(parent));
    int cnt = 0;
    for(int i = 1;i<=M;i++) {
        int u, v;cin>>u>>v;
        int uu = find(u);int vv = find(v);
        if(uu==vv) continue;
        parent[uu]=vv;st.insert(i);cnt++;
        if(cnt==N-1) {
            for(int i: st)cout<<i<<'\n';
            return 0;
        }
    }
    cout<<"Disconnected Graph\n";
    return 0;

}