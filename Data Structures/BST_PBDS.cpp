//https://dmoj.ca/problem/ds4
//PBDS edition
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int N, M, pre;
ordered_set bst;
int main(){
    cin>>N>>M;
    for(int i = 0,x; i < N; i++){
        cin>>x; bst.insert(x);
    }
    for(int i = 0,v; i < M; i++){
        char c;cin>>c>>v;
        v = pre^v;
        if(c == 'I'){
            bst.insert(v);
        }
        else if(c == 'R'){
            if(*bst.lower_bound(v-1) == v){
                bst.erase(bst.lower_bound(v-1));
            }
        }
        else if(c == 'S'){
            cout << (pre = *bst.find_by_order(v-1)) << "\n";
        }
        else{
            if(*bst.lower_bound(v-1) != v){
                cout << (pre = -1) << endl;
            }
            else{
                cout << (pre = bst.order_of_key(v)+1) << "\n";
            }
        }
    }
    vector<int> v;
    for(auto &it : bst){
        v.push_back(it);
    }
    sort(v.begin(),v.end());
    for(int &i : v) cout<<i<<" ";
    return 0;
}