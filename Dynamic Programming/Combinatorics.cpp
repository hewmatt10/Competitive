//atcoder dpy
//combinatorics after sorting points, check possible ways for the block being the last block hit for every block
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int MN = 2e5 + 5;
int N,H,W;
int dp [MN];
pair<int,int> block [MN];
int factorials [MN], inverse[MN];
bool srt(const pair<int,int> &a,const pair<int,int> &b){
    return (a.first + a.second < b.first + b.second);
}
int binpow(int b, int pow){
    int res = 1;
    while(pow){
        if(pow&1){
            res = (1LL*res*b)%mod;
        }
        b = (1LL*b*b)%mod;
        pow>>=1;
    }
    return res;
}
int mod_inverse(int a){
    return binpow(a,mod-2);
}

int choose(int a, int b) {
    if(a < 0 || b < 0 || b > a) {
        return 0;
    }
    int denom = (1LL*inverse[b]%mod*inverse[a-b]%mod);
    int res = (1LL*factorials[a]%mod*denom%mod)%mod;
    return res;
}

int main() {
    factorials[0] = inverse[0] = 1;
    for(int i = 1; i < MN; ++i) {
        factorials[i] = ((1LL*factorials[i-1])%mod * i)%mod;
        inverse[i] = mod_inverse(factorials[i]);
    }
    scanf("%d %d %d", &H, &W, &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &block[i].first, &block[i].second);
    }
    sort(block, block+N, srt);
    block[N] = {H,W};
    for(int i = 0; i <= N; ++i) {
        int curx = block[i].first, cury = block[i].second;
        int tmp = choose(curx+cury-2,curx-1);
        for(int j = 0; j < i; ++j) {
            int prevx = block[j].first,prevy = block[j].second;
            if(prevx <= curx && prevy <= cury) {
                int temp = (1LL*dp[j] * choose(curx+cury-prevx-prevy,curx-prevx)%mod)%mod;
                tmp = (tmp-temp+mod)%mod;
            }
        }
        dp[i] = tmp;
    }
    printf("%d\n", dp[N]);
}
