#include <bits/stdc++.h>
using namespace std;
char mp[50][50];
int f[30];
unordered_set<int> ed[30];
int N, M;
int dx[] = {1, 0};
int dy[] = {0, 1};
bool dead[30];
bool isin(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < M;
}

void Solve(){
    scanf("%d%d", &N, &M);
    for(int i = 0 ; i < 26 ; i++){
        ed[i].clear();
    }
    for(int i = 0 ; i < N ; i++){
        scanf("%s", mp[i]);
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            for(int k = 0 ; k < 2 ; k++){
                int ti = i + dx[k], tj = j + dy[k];
                if(isin(ti, tj)){
                    if(mp[i][j] != mp[ti][tj]){
                        ed[mp[i][j] - 'A'].insert(mp[ti][tj] - 'A');
                        ed[mp[ti][tj] - 'A'].insert(mp[i][j] - 'A');
                    }
                }
            }
        }
    }
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &f[i]);
    }
    int SF;
    scanf("%d", &SF);
    memset(dead, false, sizeof(dead));
    bool ans = false;
    for(int l = 0 ; l < N ; l++){
        int min_p = INT_MAX, min_id = -1;
        for(int i = 0 ; i < N ; i++){
            if(!dead[i]){
                int p = f[i];
                for(int j : ed[i]){
                    p += f[j] / (ed[i].size() + 1);
                }
                if(p < min_p){
                    min_p = p;
                    min_id = i;
                }
            }
        }
        if(min_p >= SF){
            ans = true;
            break;
        }
        dead[min_id] = true;
        for(int i : ed[min_id]){
            f[i] -= f[i] / (ed[i].size() + 1);
            ed[i].erase(min_id);
        }
    }
    if(ans)printf("Human\n");
    else printf("Saruman\n");
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
}
