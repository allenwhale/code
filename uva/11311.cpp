#include <bits/stdc++.h>
using namespace std;

int dp[50][50][50][50];
int R, C, M, N;

int dfs(int x1, int y1, int x2, int y2){
    int &res = dp[x1][y1][x2][y2];
    if(res != -1)
        return res;
    bool win = false;
    for(int i=x1+1;i<=R&&!win;i++)
        win |= dfs(i, y1, x2, y2) == 1;
    for(int i=y1+1;i<=C&&!win;i++)
        win |= dfs(x1, i, x2, y2) == 1;
    for(int i=x2-1;i>=R&&!win;i--)
        win |= dfs(x1, y1, i, y2) == 1;
    for(int i=y2-1;i>=C&&!win;i--)
        win |= dfs(x1, y1, x2, i) == 1;
    return res = (win ? 0 : 1);
}

void Solve(){
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d%d", &M, &N, &R, &C);
    int ans = dfs(0, 0, M - 1, N - 1);
    if(ans == 0)
        printf("Gretel\n");
    else 
        printf("Hansel\n");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
