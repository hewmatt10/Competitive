//range minimum query and range maximum query
#include <bits/stdc++.h>
using namespace std;
const int MM=5e4+3,LOG=16;
int mi[LOG][MM],mx[LOG][MM];
int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int n,q; cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>mi[0][i]; mx[0][i]=mi[0][i];
    }
    for (int i=1;i<LOG;i++) {
        for (int j=1;j+(1<<i)-1<=n;j++) {
            mi[i][j]=min(mi[i-1][j],mi[i-1][j+(1<<(i-1))]);
            mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
        }
    }
    for (int i=0,a,b;i<q;i++) {
        cin>>a>>b;
        int k=31 - __builtin_clz(b-a+1);//essentially log
        cout<<max(mx[k][a],mx[k][b-(1<<k)+1]) << min(mi[k][a],mi[k][b-(1<<k)+1])<<"\n";
    }
    return 0;
}
