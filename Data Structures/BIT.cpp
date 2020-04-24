//binary index tree template
#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;
int bit [MN];

void update(int pos, int val){
    for(int i = pos;i<MN;i+=(i&(-i)))bit[i]+=val;
}

int query(int pos){
    int ans = 0;
    for(int i = pos;i>0;i-=(i&(-i)))ans+=bit[i];
    return ans;
}

int main() {
}