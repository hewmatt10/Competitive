//atcode dpr
//matrix exponentation optimization
//matrix multiplication complexity : N^3
//binary exponentation complexity : logK
//overall time complexity N^3logK
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
const int MN = 55;
int N;ll K;
struct matrix{
    ll mat[MN][MN];
};
matrix operator*(matrix f, matrix s){
    matrix ans;
    for(int i = 0;i<MN;i++){
        for(int j = 0;j<MN;j++){
            ans.mat[i][j] = 0;
        }
    }
    for(int i = 0;i<MN;i++){
        for(int j = 0;j<MN;j++){
            for(int k = 0;k<MN;k++){
                ans.mat[i][j] += f.mat[i][k]*s.mat[k][j];
                if(ans.mat[i][j] > MOD) ans.mat[i][j] %= MOD;
            }
        }
    }
    return ans;
}
matrix matbinpow(matrix base,ll pow){
    matrix ret;
    for(int i = 0;i<MN;i++){
        for(int j = 0;j<MN;j++){
            ret.mat[i][j] = (i == j);
        }
    }
    while(K > 0){
		if(K & 1) ret = ret * base;
		base = base*base;
		K >>= 1;
	}
	return ret;
}
int main() {
    matrix base;
    scanf("%d %lld", &N, &K);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            scanf("%lld", &base.mat[i][j]);
        }
    }
    matrix ans = matbinpow(base,K);
    ll paths = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            paths = (paths + ans.mat[i][j]) % MOD;
        }
    }
    printf("%lld\n", paths);
    return 0;
}
