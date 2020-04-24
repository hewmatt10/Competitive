//https://dmoj.ca/problem/dwite07c3p3
//naive 0-1 knapsack algorithm
#include<bits/stdc++.h>
#include<string>
using namespace std;
const int maxn=101;
int main(){
    for(int z = 0;z<5;z++){
        string temp;
        int w[maxn],v[maxn];
        int n,W;    
        int dp[maxn+1][maxn+1];
        memset(dp, 0, sizeof(dp));
        cin>>W;
        cin>>n;
        for(int q=1;q<=n;q++){
            cin>>temp>>v[q]>>w[q];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(j<w[i])dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
        cout<<dp[n][W]<<'\n';
    }
}
