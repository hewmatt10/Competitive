//CCC '03 S4
//Suffix Tree implementation
#include <bits/stdc++.h>
using namespace std;
string LCP(string X, string Y){
    int i = 0, j = 0;
    while (i < X.length() && j < Y.length()){
        if (X[i] != Y[j])
            break;
        i++, j++;
    }
    return X.substr(0, i);
}

string findLCP(vector<string> const &words){
    string prefix = words[0];
    for (string s: words)
        prefix = LCP(prefix, s);
    return prefix;
}
int main() {
    int a;
    cin>>a;
    for(int n = 0;n<a;n++){
        string s;
        cin>>s;
        int x =s.length();
        string arr[x];
        for(int i = 0;i<x;i++){
            arr[i]=s.substr(i);
        }
        sort(arr,arr+x);
        int tot = 0;
        for(int i = 0;i<x-1;i++){
            vector <string> words{arr[i],arr[i+1]};
            int max = findLCP(words).length();
            tot+=max;
        }
        int y =x*(x+1)/2;
        cout<<y-tot+1<<"\n";
    }
}