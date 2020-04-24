//https://dmoj.ca/problem/lazy
//bitwise operators don't work on this problem for some reason
//seg tree lazy propagation
//creds to explosion for helping out!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll seg[400001],inc[400001],upd[400001];

void build(int node, int start, int finish, int index, ll value){
    if (start==finish){seg[node]=value;return;}
    int mid=(start+finish)/2;
    if (index<=mid)build(node*2,start,mid,index,value);
    else if (index>mid)build(node*2+1,mid+1,finish,index,value);
    seg[node]=min(seg[node*2],seg[node*2+1]);
    return;
}

void push_increment(int node, int start, int finish){
    if (inc[node]==0)return;
    seg[node]+=inc[node];
    if (upd[node*2])upd[node*2]+=inc[node];
    else inc[node*2]+=inc[node];
    if (upd[node*2+1])upd[node*2+1]+=inc[node];
    else inc[node*2+1]+=inc[node];
    inc[node]=0;
    int mid=(start+finish)/2;
    if (start==mid){
        if (upd[node*2]){
            seg[node*2]=upd[node*2];
            upd[node*2]=0;
        }
        seg[node*2]+=inc[node*2];
        inc[node*2]=0;
    }
    if (mid+1==finish){
        if (upd[node*2+1]){
            seg[node*2+1]=upd[node*2+1];
            upd[node*2+1]=0;
        }
        seg[node*2+1]+=inc[node*2+1];
        inc[node*2+1]=0;
    }
}

void push_update(int node,int start, int finish){
    if (upd[node]==0)return;
    seg[node]=upd[node];
    upd[node*2]=upd[node*2+1]=upd[node];
    inc[node*2]=inc[node*2+1]=0;
    upd[node]=0;
    int mid=(start+finish)/2;
    if (start==mid){
        seg[node*2]=upd[node*2];
        upd[node*2]=0;
    }
    if (mid+1==finish){
        seg[node*2+1]=upd[node*2+1];
        upd[node*2+1]=0;
    }
}

void increment(int node, int start, int finish, int l, int r, ll value){
    if (l>r || start > r || finish < l || finish<start){
        push_update(node,start,finish);
        push_increment(node,start,finish);
        return;
    }
    if (start>=l && finish<=r){
        if (start==finish){
            seg[node]+=inc[node];
            if (upd[node])seg[node]=upd[node];
            inc[node]=upd[node]=0;
            seg[node]+=value;
        }
        else{
            if (upd[node])upd[node]+=value;
            else inc[node]+=value;
            push_update(node,start,finish);
            push_increment(node,start,finish);
        }
        return;
    }
    push_update(node,start,finish);
    push_increment(node,start,finish);
    int mid=(start+finish)/2;
    increment(node*2,start,mid,l,r,value);
    increment(node*2+1,mid+1,finish,l,r,value);
    seg[node]=min(seg[node*2],seg[node*2+1]);
}

void update(int node, int start, int finish, int l, int r, ll value){
    if (l>r || start > r || finish < l || finish<start){
        push_increment(node,start,finish);
        push_update(node,start,finish);
        return;
    }
    if (start>=l && finish<=r){
        if (start==finish){
            seg[node]+=inc[node];
            if (upd[node])seg[node]=upd[node];
            inc[node]=upd[node]=0;
            seg[node]=value;
        }
        else{
            upd[node]=value;
            inc[node]=0;
            push_increment(node,start,finish);
            push_update(node,start,finish);
        }
        return;
    }
    push_increment(node,start,finish);
    push_update(node,start,finish);
    int mid=(start+finish)/2;
    update(node*2,start,mid,l,r,value);
    update(node*2+1,mid+1,finish,l,r,value);
    seg[node]=min(seg[node*2],seg[node*2+1]);
}

ll query(int node, int start, int finish, int l, int r){
    if (l>r || start > r || finish < l || finish<start){
        return LONG_LONG_MAX;
    }
    if (start>=l && finish<=r){
        if (start==finish){
            seg[node]+=inc[node];
            if (upd[node])seg[node]=upd[node];
            inc[node]=upd[node]=0;
        }
        else{
            push_update(node,start,finish);
            push_increment(node,start,finish);
        }
        return seg[node];
    }
    push_update(node,start,finish);
    push_increment(node,start,finish);
    int mid=(start+finish)/2;
    return min(query(node*2,start,mid,l,r),query(node*2+1,mid+1,finish,l,r));
}

int N,Q;
int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 0,a;i<N;i++){
        scanf("%d", &a);
        build(1,1,N,i+1,a);
    }
    for(int i = 0,a,b,c,d;i<Q;i++){
        scanf("%d ",&a);
        if(a==1){
            scanf("%d %d %d", &b, &c, &d);
            increment(1,1,N,b,c,d);
        }
        else if(a == 2){
            scanf("%d %d %d", &b, &c, &d);
            update(1,1,N,b,c,d);
        }
        else{
            scanf("%d %d", &b, &c);
            printf("%lld\n",query(1,1,N,b,c));
        }
    }
    return 0;
}