#include <bits/stdc++.h>
using namespace std;

void Solve(int N){
    vector<int> a(N + 1);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &a[i]);
    }
    vector<int> sum(2 * N + 1);
    for(int i = 0 ; i < N ; i++){
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 0 ; i < N ; i++){
        sum[i + N] = sum[i - 1 + N] + a[i];
    }
    int ans = 0, l = 0, r = 0;
    vector<int> q(N * 2);
    for(int i = 0 ; i < 2 * N ; i++){
        while(l < r && sum[q[r - 1]] >= sum[i]) r--;
        q[r++] = i;
        if(i >= N && sum[q[l]] >= sum[i - N])ans++;
        while(l < r && i - q[l] + 1 > N)l++;

    }
    printf("%d\n", ans);
}

int main(){
    int N;
    while(~scanf("%d", &N) && N){
        Solve(N);
    }
    return 0;
}
