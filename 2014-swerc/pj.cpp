#include <bits/stdc++.h>
using namespace std;
char c[2048][2048];
typedef long long ll;
#define MAX 2
#define MOD 1000000007
ll ht[MAX][2048][2048];
ll hc[MAX][2] = {
    {2, 3},
    {3, 5}
};
ll mo[MAX][2];
void build(int h, int w){
    for(int k = 0 ; k < MAX ; k++){
        for(int i = 1 ; i <= h ; i++){
            for(int j = 1 ; j <= w ; j++){
                ht[k][i][j] = ht[k][i-1][j] * hc[k][0] + ht[k][i][j-1] * hc[j][1] + (c[i][j] == 'o');
                ht[k][i][j] %= MOD;
            }
        }
    }
}

int main(){
    int h, w, H, W;
    scanf("%d%d%d%d", &h, &w, &H, &W);
    ll pattern[MAX];
    int ans = 0;
    for(int i = 1 ; i <= h ; i++){
        scanf("%s", c[i] + 1);
    }
    build(h, w);
    for(int i = 0 ; i < MAX ; i++){
        pattern[i] = ht[i][h][w];
    }
    for(int i = 1 ; i <= H ; i++){
        scanf("%s", c[i] + 1);
    }
    build(H, W);
    for(int k = 0 ; k < MAX ; k++){
        mo[k][0] = mo[k][1] = 1;
        for(int i = 0 ; i < h ; i++){
            mo[k][0] = mo[k][0] * hc[k][0] % MOD;
        }
        for(int i = 0 ; i < w ; i++){
            mo[k][1] = mo[k][1] * hc[k][1] % MOD;
        }
    }
    for(int i = h ; i <= H ; i++){
        for(int j = w ; j <= W ; j++){
            bool flag = true;
            for(int k = 0 ; k < MAX ; k++){
                ll now = ht[k][i][j] - (ht[k][i-h][j] * mo[k][0] % MOD) - (ht[k][i][j-w] * mo[j][1] % MOD) + (ht[k][i-h][j-w] * mo[k][0] % MOD * mo[k][1] % MOD);
                now %= MOD;
                if(now != pattern[k]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
