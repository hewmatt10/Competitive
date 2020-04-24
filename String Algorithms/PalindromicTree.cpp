//APIO '14 P1 Palindromes
//uses the data structure palindromic tree
//https://codeforces.com/blog/entry/13958
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int MN = 3e5+7;
ll ans;
int  slen, node, prv,len[MN],link[MN],nxt[MN][26],cnt[MN];
char str[MN];
string s;
void init(){
    str[0]=-1;slen = 1;link[0]=1;len[1]=-1;node = 2;
}
int getLink(int u){
    while(str[slen-len[u]-2]!=str[slen-1])u=link[u];
    return u;
}
void insert(char c){
    c = c-'a';
    str[slen++] = c;
    prv = getLink(prv);
    if(!nxt[prv][c]){
        len[node] = len[prv]+2;
        link[node] = nxt[getLink(link[prv])][c];
        nxt[prv][c] = node;
        node++;
    }
    prv = nxt[prv][c];
}
int main(){
    init();
    cin>>s;
    for(int i = 0;i<s.length();i++){
        insert(s[i]);
        cnt[prv]++;
    }
    for(int i = node-1;i>1;i--){
        cnt[link[i]]+=cnt[i];
    }
    for(int i = 2;i<node;i++)ans = max(ans, 1LL* len[i]*cnt[i]);
    printf("%lld\n", ans);
    return 0;
}