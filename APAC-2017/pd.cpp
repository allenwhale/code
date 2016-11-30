#include <bits/stdc++.h>
using namespace std;
int s[5010];
int N, P;
vector<pair<int, int>> cut[5010];
vector<int> work;
int dp[5010];
bool ans;
int K = 1;
void find(int x){
    //printf("x %d\n" ,x);
    if(ans)return;
    //if((int)work.size() + dp[x] < K)return;
    if(x == N){
        auto W = work;
        sort(W.begin(), W.end());
        int cnt = 0;
        for(int i=0;i<(int)W.size();i++)
            cnt += W[i] != work[i];
        if(cnt <= P){
            K = max(K, (int)work.size());
            ans = true;   
        }
        return;
    }
    for(auto i : cut[x]){
        work.push_back(i.second);
        find(i.first + 1);
        if(ans)return;
        work.pop_back();
    }
}
int Solve(){
    scanf("%d%d", &N, &P);
    for(int i=0;i<N;i++){
        scanf("%d", &s[i]);
        cut[i].clear();
    }
    for(int i=0;i<N;i++){
        int mn = s[i], mx = s[i];
        for(int j=i;j<N;j++){
            mn = min(mn, s[j]);
            mx = max(mx, s[j]);
            if(mx - mn + 1 == j - i + 1)
                cut[i].push_back({j, mn});
        }
    }
    dp[N] = 0;
    for(int i=N-1;i>=0;i--){
        dp[i] = 0;
        for(auto j : cut[i])
            dp[i] = max(dp[i], dp[j.first + 1] + 1);
    }
    for(int i=0;i<10;i++)
        printf("%d %d\n",i, dp[i]);
    ans = false;
    work.clear();
    find(0);
    return K;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: %d\n", t, Solve());
    }
    return 0;
}

