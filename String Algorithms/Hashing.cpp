//CCC '20 S3 Searching for Strings
//naive search requires substring, we can lower time complexity by a factor of N by using hashing 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 2e5+5,base = 131;
int m, n, cnt [26], psa[MN][26];
ll hsh[MN], power[MN];
unordered_set<ll> vis;
string s,t;
int main() {
    cin >> s >> t;
    hsh[0] = 0; power[0] = 1;
     m = s.size(); n = t.size();
    for(int i=0; i<m; i++) cnt[s[i]-'a']++;
    for(int i=1; i<=n; i++){
        hsh[i] = hsh[i-1]*base + t[i-1];
        power[i] = power[i-1]*base;
        psa[i][t[i-1]-'a']++;
        for(int j=0; j<26; j++) psa[i][j] += psa[i-1][j];
    }
    for(int i = m; i<=n; i++){
        bool flag = true;
        for(int j=0; j<26; j++){
            if(psa[i][j]-psa[i-m][j] != cnt[j]) {
                flag = false; break;
            }
        }
        if(flag) vis.insert(hsh[i] - hsh[i-m]*power[m]);
    }
    cout<<vis.size();
}