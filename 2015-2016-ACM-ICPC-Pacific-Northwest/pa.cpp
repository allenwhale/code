#include <bits/stdc++.h>
using namespace std;
#define MAX 512
int d[MAX][MAX];
int direct[MAX][MAX];
int p[MAX];
struct S{
    int s, f, t;
    S(){}
    S(int _s, int _f, int _t) : s(_s), f(_f), t(_t) {}
};

vector<int> vc[MAX];
int my[MAX], mx[MAX];
bool visy[MAX];

bool match(int x){
    for(int y: vc[x]){
        if(visy[y] == false){
            visy[y] = true;
            if(my[y] == -1 || match(my[y])){
                mx[x] = y, my[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<S> s(m);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &p[i]);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            scanf("%d", &d[i][j]);
            direct[i][j] = d[i][j] + p[j];
            d[i][j] += p[j];
            if(i == j)d[i][i] = 0;
        }
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &s[i].s, &s[i].f, &s[i].t);
        s[i].s--, s[i].f--;
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i == j)continue;
            int dis = s[i].t + direct[s[i].s][s[i].f] + d[s[i].f][s[j].s];
            if(dis <= s[j].t){
                vc[i].push_back(j);
            }
        }
    }
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
    int ans = m;
    for(int i = 0 ; i < m ; i++){
        if(mx[i] == -1){
            memset(visy, false, sizeof(visy));
            if(match(i))ans--;
        }
    }
    printf("%d\n", ans);
    return 0;
}
