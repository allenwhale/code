#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<array<int, 3>> ed[200010];
int out[200010], in[200010];
int dir[200010];
int a[200010], b[200010];

int main(){
    scanf("%d%d", &N, &M);
    for(int i=0;i<M;i++){
        int c;
        scanf("%d%d%d", &a[i], &b[i], &c);   
        ed[a[i]].push_back({{b[i], c, i}});
        ed[b[i]].push_back({{a[i], c, i}});
        out[a[i]] += c;
        out[b[i]] += c;
    }
    queue<int> q;
    q.push(1);
    out[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto &e : ed[now]){
            int to = e[0], c = e[1];
            if(in[to] == out[to] && to != N)continue;
            in[to] += c;
            out[to] -=c;
            if(in[to] == out[to] && to != N)q.push(to);
            dir[e[2]] = a[e[2]] == to;
        }
    }
    for(int i=0;i<M;i++)
        printf("%d\n", dir[i]);
    return 0;
}
