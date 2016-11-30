#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
struct node{
    vector<int> ch;
    int label;
    int total;
}node[MAXN];
int pool = 0;
int new_node(){
    node[pool].total = 0;
    node[pool].ch.clear();
    return pool++;
}
char in[1010];
char *s;
int parse(){
    int tr = new_node();
    node[tr].label = *(++s) - 'A';
    ++s;
    while(*s == '('){
        node[tr].ch.push_back(parse());
    }
    ++s;
    return tr;
}
void print(int x, int dep=0){
    for(int i=0;i<dep;i++)
        printf(" ");
    printf("%d\n", node[x].label);
    for(int c : node[x].ch)
        print(c, dep + 1);
}
void dfs(int x){
    node[x].total = 1;
    for(int i = 0 ; i < (int)node[x].ch.size() ; i++){
        int u = node[x].ch[i];
        dfs(u);
        node[x].total += node[u].total;
    }
}
int cmp(int x, int y){
    int re = 0;
    if(node[x].label != node[y].label){
        re++;
    }
    if(node[x].ch.size() == node[y].ch.size()){
        for(int i = 0 ; i < (int)node[x].ch.size() ; i++){
            re += cmp(node[x].ch[i], node[y].ch[i]);
        }
    } else if(node[x].ch.size() > node[y].ch.size()){
    } else {
    }
    return re;
}
void Solve(){
    pool = 0;
    scanf("%s", in);
    s = in;
    int root1 = parse();
    dfs(root1);
    scanf("%s", in);
    s = in;
    int root2 = parse();
    dfs(root2);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
}
