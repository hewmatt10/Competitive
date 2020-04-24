//binary search tree the classic way
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5+5;
struct node {
    ll key, h, s;
    node *left, *right;
    node(ll key) : key(key), h(1), s(1), left(NULL), right(NULL) {}

};
bool empty(node *root){
    return (root == NULL);
}
int height(node *root){
    return (root == NULL) ? 0 : root -> h;
}
int size(node *root){
    return (root == NULL) ? 0 : root -> s;
}
node *minNode(node *root){
    node *trav = root;
    while(!empty(trav->left)){
        trav = trav->left;
    }
    return trav;
}
int id(node *root, ll k){
    if(root == NULL)return -1;
    if(root -> key == k){//look down
        ll next = id(root -> left, k);
        return (next == -1) ? size(root->left)+1 : next;
    }
    if(root -> key > k){
        return id(root -> left, k);
    }
    else {
        ll next = id(root -> right, k);
        return (next == -1) ? -1 : size(root->left) + next + 1;
    }
}
void setVal(node *root){
    root -> h = max(height(root->left),height(root->right))+1;
    root -> s = size(root->left) + size(root->right) + 1;
}
int diff(node *root){
    return empty(root) ? -1 : (height(root->left)-height(root->right));
}

node *rotateleft(node *nl){
    node *no = nl->right;
    node *nr = no->left;
    no->left = nl;
    nl->right = nr;
    setVal(nl);setVal(no);
    return no;
}
node *rotateright(node *nr){
    node *no = nr->left;
    node *nl = no->right;
    no->right = nr;
    nr->left = nl;
    setVal(nr);setVal(no);
    return no;
}
node *remove(node *root, ll k){
    if(root == NULL)return NULL;
    if(root->key > k) root-> left = remove(root->left,k);
    if(root->key < k) root-> right = remove(root->right,k);
    if(root->key == k){
        if(empty(root->left)&&empty(root->right)){
            return NULL;
        }
        else if(empty(root->left))root = root -> right;
        else if(empty(root->right))root = root -> left;
        else{
            node *t = minNode(root->right);
            root->key = t->key;
            root->right = remove(root->right,root->key);
        }
    }
    setVal(root);
    if(diff(root) > 1 && diff(root->left) >= 0){
        return rotateright(root);
    }if(diff(root) > 1 && diff(root->left) < 0){
        root->left = rotateleft(root->left);
        return rotateright(root);
    }if(diff(root) < -1 && diff(root->right) <= 0){
        return rotateleft(root);
    }if(diff(root) < -1 && diff(root->right) > 0){
        root->right = rotateright(root->right);
        return rotateleft(root);
    }
    return root;
}
node * insert(node *root, long long key) {
    if (empty(root)) {
        return new node(key);
    }
    if (key >= root->key) {
        root->right = insert(root->right, key);
    }if (key < root->key) {
        root->left = insert(root->left, key);
    }
    setVal(root);
    if (diff(root) > 1 && diff(root->left) >= 0) {
        return rotateright(root);
    }if (diff(root) > 1 && diff(root->left) < 0) {
        root->left =  rotateleft(root->left);
        return rotateright(root);
    }if (diff(root) < -1 && diff(root->right) <= 0) {
        return rotateleft(root);
    }if (diff(root) < -1 && diff(root->right) > 0) {
        root->right = rotateright(root->right);
        return rotateleft(root);
    }return root;
}
ll search(node *root, ll k){
    if(empty(root))return NULL;
    int pos = size(root->left)+1;
    if(pos == k)return root->key;
    else if(pos > k)return search(root->left,k);
    else return search(root->right,k-pos);
}
void printArr(node *root){
    if(empty(root))return;
    printArr(root->left);
    printf("%lld ", root->key);
    printArr(root->right);
}
ll N, M,v,u,track = 0;
char c;
int main(){
    node *rt = NULL;
    cin>>N>>M;
    for(int i = 0;i<N;i++){
        cin>>v;
        rt = insert(rt,v);
    }
    for(int i = 0;i<M;i++){
        scanf(" %c %lld", &c, &v);
        if (c == 'S') {
            track = search(rt, (v ^ track));
            printf("%lld\n", track);
        } else if (c == 'L') {
            track = id(rt, v ^ track);
            printf("%lld\n", track);
        } else if (c == 'I') {
            rt = insert(rt, v ^ track);
        } else {
            rt = remove(rt, v ^ track);
        }
    }
    printArr(rt);
}