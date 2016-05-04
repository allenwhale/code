#include <bits/stdc++.h>
using namespace std;
struct trie{
    trie *c[2];
    int idx;
    trie(){
        c[0] = c[1] = NULL;
        idx = INT_MAX;
    }
};
void insert(trie *tr, int n, int idx){
    for(int i=31;i>=0;i--){
        if(tr->c[(n>>i)&1] == NULL){
            tr->c[(n>>i)&1] = new trie();
        }
        tr = tr->c[(n>>i)&1];
    }
    tr->idx = min(tr->idx, idx);
}
int solve(trie *tr, int n){
    for(int i=31;i>=0;i--){
        int now = (n>>i)&1;
        if(tr->c[now^1]) tr = tr->c[now^1];
        else tr = tr->c[now];
    }
    return tr->idx;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        trie *root = new trie();
        int N, Q;
        scanf("%d%d", &N, &Q);
        for(int i=0;i<N;i++){
            int x;
            scanf("%d", &x);
            insert(root, x, i);
        }
        for(int i=0;i<Q;i++){
            int x;
            scanf("%d", &x);
            if(x < 0) x = ~x;
            printf("%d\n", solve(root, x) + 1);
        }
        if(T)puts("");
    }
    return 0;
}
