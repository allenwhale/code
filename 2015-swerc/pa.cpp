#include <bits/stdc++.h>
using namespace std;
int A, B, E, P;
vector<int> vc[5010];
int deg[5010], w_deg[5010];
pair<int, int> Solve(int x){
    memcpy(w_deg, deg, sizeof(deg));
    int cnt = 0;
    vector<int> zero;
    queue<vector<int>> q;
    for(int i=0;i<E;i++){
        if(w_deg[i] == 0)
            zero.push_back(i);
    }
    q.push(zero);
    zero.clear();
    while(!q.empty()){
        auto now = q.front(); q.pop();
        if(cnt + (int)now.size() == x){
            return {cnt + (int)now.size(), E - (cnt + (int)now.size())};
        }else if(cnt + (int)now.size() > x){
            return {cnt, E - (cnt + (int)now.size())};
        }
        cnt += now.size();
        for(int u : now){
            for(int v : vc[u]){
                w_deg[v]--;
                if(w_deg[v] == 0)
                    zero.push_back(v);
            }
        }
        if(zero.size())
            q.push(zero);
        zero.clear();
    }
    return {0, 0};
}
int main(){
    scanf("%d%d%d%d", &A, &B, &E, &P);
    for(int i=0;i<P;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        vc[a].push_back(b);
        deg[b]++;
    }
    auto solvea = Solve(A);
    auto solveb = Solve(B);
    printf("%d\n%d\n%d\n", solvea.first, solveb.first, solveb.second);
    return 0;
}
