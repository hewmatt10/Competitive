//CCC '10 S4 Animal Farm
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int MN = 105;

int N,par[MN],rnk[MN],pen[MN],cost[MN];

void initialize(int N){
    for(int i = 0;i<=N;i++){
        par[i]=i;
        rnk[i]=1;
    }
}
int find(int x){
    return (par[x]==x) ? x : (par[x]=find(par[x]));
}

bool check(int x, int y){
    return find(x)==find(y);
}

void merge(int x, int y){
    if(!check(x,y)){
        int a = find(x);
        int b = find(y);
        if(rnk[a]>rnk[b]){
            rnk[a]+=rnk[b];
            par[b]=a;
        }
        else{
            rnk[b]+=rnk[a];
            par[a]=b;
        }
    }
}
set<pii> temp;
map<pii,int> f, s;
vector<pair<int,pii>> fir;
vector<pair<int,pii>> sec;
int main() {
    scanf("%d",&N);
    for(int _ = 1;_<=N;_++){
        int t;
        scanf("%d",&t);
        for(int i = 0;i<t;i++)
            scanf("%d",&pen[i]);
        for(int i = 0;i<t;i++)
            scanf("%d",&cost[i]);
        for(int i = 0;i<t;i++){
            int m = pen[i];
            int n = pen[(i+1)%t];
            if(m>n)swap(m,n);
            pii tt = make_pair(m,n);
            if(temp.count(tt)){
                fir.push_back(make_pair(cost[i],make_pair(_,f[tt])));
                sec.push_back(make_pair(cost[i],make_pair(_,f[tt])));
                temp.erase(tt);
            }
            else{
                temp.insert(tt);
                f[tt]=_;
                s[tt]=cost[i];
            }
        }
    }
    for(pii x : temp){
        sec.push_back(make_pair(s[x],make_pair(0,f[x])));
    }
    initialize(N);
    sort(fir.begin(),fir.end());
    sort(sec.begin(),sec.end());
    int ans1 = 0,ans2 = 0;
    for(pair<int,pii> i : fir){
        if(!check(i.second.first,i.second.second)){
            ans1+=i.first;
            merge(i.second.first,i.second.second);
        }
    }
    initialize(N);
    for(pair<int,pii> i : sec){
        if(!check(i.second.first,i.second.second)){
            ans2+=i.first;
            merge(i.second.first,i.second.second);
        }
    }
    cout<<min(ans1,ans2)<<'\n';
    return 0;
}
