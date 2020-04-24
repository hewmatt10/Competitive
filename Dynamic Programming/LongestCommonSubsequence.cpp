//atcoder dpf
//in this problem it is longest common string, but idea is same
#include <bits/stdc++.h>
using namespace std;
string s, t; int dp[3002][3002];
stack<char> stk;
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin >> s >> t;
    for(int i=1; i<=(int)s.size(); i++){
        for(int j=1; j<=(int)t.size(); j++){
            (s[i-1] == t[j-1]) ? dp[i][j] = dp[i-1][j-1] + 1 :  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = s.size(), j = t.size();
    while( i!=0 && j!=0){
        if(dp[i][j] == dp[i-1][j])i --;
        else if(dp[i][j] == dp[i][j-1]) j--;
        else { stk.push(s[i-1]); i--; j--; }
    }
    while(!stk.empty()){
        cout<<stk.top();stk.pop();
    }
}
