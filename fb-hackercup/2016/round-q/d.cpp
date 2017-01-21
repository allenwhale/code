#include <bits/stdc++.h>
using namespace std;
struct Trie{
    char c;
    int p;
    Trie *t[26];
    int dp[310];
    Trie(char _c='a'){
        c = _c; p = 0;
        memset(t, 0, sizeof(t));
        memset(dp, 0, sizeof(dp));
    }
} *root;
void insert(Trie *tr, char s[]){
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(tr->t[s[i] - 'a'])
            tr = tr->t[s[i] - 'a'];
        else
            tr = tr->t[s[i] - 'a'] = new Trie(s[i]);
    }
    tr->p++;
}
void dfs(Trie *tr){
}
char tmp[100010];
int Solve(){
    int N, K;
    scanf("%d%d", &N, &K);
    root = new Trie();
    for(int i=0;i<N;i++){
        scanf("%s", tmp);
        insert(root, tmp);
    }
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
        printf("Case #%d: %d\n", t, Solve());

    return 0;
}
