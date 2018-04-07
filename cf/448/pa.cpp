#include <bits/stdc++.h>
using namespace std;

int a[500], sum[1010];
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++)
        scanf("%d", &a[i]);
    for(int i = 1 ; i <= N ; i++)
        sum[i] = sum[i - 1] + a[i];
    for(int i = N + 1 ; i <= N + N ; i++)
        sum[i] = sum[i - 1] + a[i - N];
    int ans = INT_MAX;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j <= N ; j++){
            int d = sum[i + j - 1] - sum[i - 1];
            ans = min(ans, abs(360 - d - d));
        }
    }
    printf("%d\n", ans);
    return 0;
}
