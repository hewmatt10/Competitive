//APIO '17 P2 Travelling Merchant
#include <bits/stdc++.h>
#define fori(a,b) for(auto i = a;i<b;++i)
#define forj(a,b) for(auto j = a;j<b;++j)
#define fork(a,b) for(auto k = a;k<b;++k)
#define revi(a,b) for(auto i = a;i>b;--i)
#define revj(a,b) for(auto j = a;j>b;--j)
#define revk(a,b) for(auto k = a;k>b;--k)
using namespace std;

#define ll long long
const ll LLM = LLONG_MAX;
const int MN=100, MK=1000;
int N, M, K, x[MN][MK], y[MN][MK], a[MN][MN];
ll u[MN][MN], v[MN][MN];

void calc(ll arr[MN][MN]) {
    fork(0,N)
        fori(0,N)
            forj(0,N)
                arr[i][j]=min(arr[i][k]+arr[k][j], arr[i][j]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i=0; i<N; ++i)
        for(int j=0; j<K; ++j)
            cin >> x[i][j] >> y[i][j];
    fori(0,N)
        forj(0,N)
            fork(0,K)
                if(x[i][k]!=-1&&y[j][k]!=-1)
                    a[i][j]=max(y[j][k]-x[i][k], a[i][j]);
    memset(u, 0x3F, sizeof(u));
    fori(0,M) {
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        u[--aa][--bb]=cc;
    }
    calc(u);
    //binary search
    ll left=1, right=1e9;
    while(left<=right) {
        ll mid=(left+right)/2;
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                v[i][j]=mid*min(u[i][j], LLM/2/mid)-a[i][j];
        calc(v);
        bool flag=false;
        fori(0,N)
            if(v[i][i]<=0){flag = true;break;}
        if(flag)
            left=mid+1;
        else
            right=mid-1;
    }
    cout << right << '\n';
}
