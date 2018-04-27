#include <bits/stdc++.h>
using namespace std;

int R, C, H, V;
char mp[500][500];
int vsum[500], hsum[500];
int res[500][500];
void Solve(){
    memset(res, 0, sizeof(res));
    memset(vsum, 0, sizeof(vsum));
    memset(hsum, 0, sizeof(hsum));
    scanf("%d%d%d%d", &R, &C, &H, &V);
    for(int i = 0 ; i < R ; i++)
        scanf("%s", mp[i]);
    int total = 0;
    for(int i = 0 ; i < R ; i++)
        for(int j = 0 ; j < C ; j++)
            vsum[j] += mp[i][j] == '@', hsum[i] += mp[i][j] == '@', total += mp[i][j] == '@';
    if(total % ((H + 1) * (V + 1)) != 0 || total % (H + 1) != 0 || total % (V + 1) != 0){
        printf("IMPOSSIBLE\n");
        return;
    }
    int vavg = total / (V + 1), havg = total / (H + 1);
    int now = 0;
    vector<int> vcut, hcut;
    for(int i = 0 ; i < C ; i++){
        now += vsum[i];
        if(now > vavg){
            printf("IMPOSSIBLE\n");
            return;
        }
        if(now == vavg){
            now = 0;
            vcut.push_back(i);
        }
    }
    for(int i = 0 ; i < R ; i++){
        now += hsum[i];
        if(now > havg){
            printf("IMPOSSIBLE\n");
            return;
        }
        if(now == havg){
            now = 0;
            hcut.push_back(i);
        }
    }

    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            int pi = lower_bound(hcut.begin(), hcut.end(), i) - hcut.begin(), pj = lower_bound(vcut.begin(), vcut.end(), j) - vcut.begin();
            res[pi][pj] += mp[i][j] == '@';
        }
    }
    int last = res[0][0];
    for(int i = 0 ; i <= H ; i++){
        for(int j = 0 ; j <= V ; j++){
            if(last != res[i][j]){
                printf("IMPOSSIBLE\n");
                return;
            }
        }
    }
    printf("POSSIBLE\n");
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1 ; i <= T ; i++){
        printf("Case #%d: ", i);
        Solve();
    }
    return 0;
}
