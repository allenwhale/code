#include <bits/stdc++.h>
using namespace std;
#define ID(i, j, k) (2 * ((i) * C + (j)) + (k))
#define f first
#define s second
int R, C;
char mp[110][110];
int v[110][110];
int f[100*100*2+10];
int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(int a, int b){
    f[find(a)] = find(b);
}
bool isin(int x, int y){
    return x >= 0 && y >= 0 && x < R && y < C;
}
typedef pair<int, pair<int, int> > Edge;
void Solve(){
    vector<Edge> ed;
    scanf("%d%d", &R, &C);
    for(int i=0;i<R*C*2;i++){
        f[i] = i;
    }
    for(int i=0;i<R;i++)
        scanf("%s", mp[i]);
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            scanf("%d", &v[i][j]);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            ed.push_back({v[i][j], {ID(i, j, 0), ID(i, j, 1)}});
            int tx, ty;
            //up
            tx = i - 1, ty = j;
            if(isin(tx, ty)){
                merge(ID(i, j, mp[i][j] == '\\'), ID(tx, ty, (mp[i][j] == '\\') ^ (mp[i][j] == mp[tx][ty])));
            }
            tx = i, ty = j - 1;
            if(isin(tx, ty)){
                merge(ID(i, j, 0), ID(tx, ty, 1));
            }
        }
    }
    sort(ed.begin(), ed.end());
    int ans = 0;
    for(auto e : ed){
        if(find(e.s.f) != find(e.s.s)){
            ans += e.f;
            merge(e.s.f, e.s.s);
        }
    }
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case %d: ", t);
        Solve();
    }
    return 0;
}
