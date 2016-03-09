#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define dist(a, b) (sqr(a.x-b.x) + sqr(a.y-b.y))
PI p[2010];
int dis[2010][2010];
int Solve(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    for(int i=0;i<N;i++)
        for(int j=i;j<N;j++)
            dis[i][j] = dis[j][i] = dist(p[i], p[j]);
    int ans = 0;
    for(int i=0;i<N;i++){
        unordered_map<int ,int> mp;
        for(int j=0;j<N;j++){
            if(i == j) continue;
            mp[dis[i][j]]++;
        }
        for(auto it: mp)
            ans += (it.second * (it.second - 1)) / 2;
    }
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: %d\n", t, Solve());
    }
    return 0;
}
