//https://dmoj.ca/problem/ds3
//segment tree
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;

const int MM = 1e5+5;
struct node{
    int l,r,v,g,f;
}seg [3*MM];

int N,M;
char op;
void pushUp(int id){
    seg[id].v = min(seg[2*id].v,seg[2*id+1].v);
    seg[id].g = __gcd(seg[2*id].g,seg[2*id+1].g);
    seg[id].f = 0;
    if(seg[id].g == seg[2*id].g) seg[id].f += seg[2*id].f;
    if(seg[id].g == seg[2*id+1].g) seg[id].f += seg[2*id+1].f;
}
void build(int l, int r, int id){
    seg[id].l = l;
    seg[id].r = r;
    if(l==r){
        scanf("%d", &seg[id].v);
        seg[id].g = seg[id].v;
        seg[id].f = 1;
        return;
    }
    int mid = (seg[id].l + seg[id].r)/2;
    build(l,mid,2*id);
    build(mid+1,r,2*id+1);
    pushUp(id);
}
void update(int pos, int val, int id){
    if(seg[id].l == pos && seg[id].r == pos){
        seg[id].v = seg[id].g = val;
        return;
    }
    int mid = (seg[id].l + seg[id].r)/2;
    if(pos<=mid)update(pos,val,2*id);
    else update(pos,val,2*id+1);
    pushUp(id);
}
int qryMin(int l, int r, int id){
    if(seg[id].l == l && seg[id].r == r) return seg[id].v;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r<=mid)return qryMin(l,r,2*id);
    else if(l>mid) return qryMin(l,r,2*id+1);
    else return min(qryMin(l,mid,2*id),qryMin(mid+1,r,2*id+1));
}
int qryGcd(int l, int r, int id){
    if(seg[id].l == l && seg[id].r == r) return seg[id].g;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r<=mid)return qryGcd(l,r,2*id);
    else if(l>mid) return qryGcd(l,r,2*id+1);
    else return __gcd(qryGcd(l,mid,2*id),qryGcd(mid+1,r,2*id+1));
}
int qryCnt (int l, int r, int g, int id){
    if(seg[id].l == l && seg[id].r == r)return g == seg[id].g ? seg[id].f : 0;
    int mid = (seg[id].l+seg[id].r)/2;
    if(r<=mid)return(qryCnt(l,r,g,2*id));
    if(l>mid)return(qryCnt(l,r,g,2*id+1));
    return qryCnt(l,mid,g,2*id)+qryCnt(mid+1,r,g,2*id+1);
}
int main() {
    scanf("%d %d", &N, &M);
    build(1,N,1);
    for(int i = 1,x,y; i<=M;i++){
        scanf(" %c %d %d", &op, &x, &y);
        if(op == 'C')update(x,y,1);
        else if(op == 'M')printf("%d\n", qryMin(x,y,1));
        else if(op == 'G')printf("%d\n", qryGcd(x,y,1));
        else if(op == 'Q'){
            int g = qryGcd(x,y,1);
            printf("%d\n", qryCnt(x,y,g,1));
        }
    }
    return 0;
}