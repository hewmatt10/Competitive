//atcoder dpj
//simple expected value algorithm
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int N,A,B,C;
ld n;
ld dp[301][301][301];
ld calc(int a,int b,int c){
    if(!a && !b &&!c) return 0;
    auto &ret = dp[a][b][c];
    if(ret)return ret;
    ret = 1.0;
    if(a){
        ret += a/n * calc(a-1,b,c);
    }
    if(b){
        ret += b/n * calc(a+1,b-1,c);
    }
    if(c){
        ret += c/n * calc(a,b+1,c-1);
    }
    ret /= 1- (n-a-b-c)/n;
    return ret;
}
int main() {
    cin>>N;
    n = (ld)N;
    for(int i = 0,x;i<N;i++){
        cin>>x;
        if(x==1)A++;
        if(x==2)B++;
        if(x==3)C++;
    }
    printf("%.30Lf\n", calc(A, B, C));
    return 0;
}