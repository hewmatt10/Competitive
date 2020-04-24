//atcoder dpz
//convex hull trick optimization to turn naive quadratic time complexity into linear time complexity 
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
#define mp make_pair
const int MN = 2e5+5;
int N;
ll C,arr[MN],dp[MN];
ld f(int i,int j){
    return(dp[i] - dp[j] + arr[i] * arr[i] - arr[j] * arr[j])/(2.0 * (arr[i]-arr[j]));
}
int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin>>N>>C;
    for(int i = 1;i<=N;i++)cin>>arr[i];
    deque<int> buf;
    buf.push_back(1);
    for(int i = 2;i<=N;i++){
        while(buf.size()>=2 && f(buf[0],buf[1]) <= arr[i])buf.pop_front();
        dp[i] = (arr[i]-arr[buf.front()])*(arr[i]-arr[buf.front()])+dp[buf.front()]+C;
        while(buf.size()>=2 && f(buf[buf.size()-1],buf[buf.size()-2]) >= f(buf[buf.size()-1],i))buf.pop_back();
        buf.push_back(i);
    }
    cout<<dp[N];
    return 0;
}
