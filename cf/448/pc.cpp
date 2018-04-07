#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007ll
int N;
int a[100010], cnt[100];
vector<int> primes;
ll dp[2][1 << 21];
void init(){
    primes.push_back(2);
    for(int j = 3; j < 71 ; j += 2){
        bool tf = true;
        for(int x : primes){
            if(j % x == 0) tf = false;
        }
        if(tf)primes.push_back(j);
    }
}
int mask(int x){
    int res = 0;
    for(int i = 0 ; i < (int)primes.size() && x >= primes[i] ; i++){
        while(x && x % primes[i] == 0){
            res ^= (1 << i);
            x /= primes[i];
        }
    }
    return res;
}
ll pow2[100010];
int main(){
    pow2[0] = 1;
    for(int i = 1 ; i < 100010 ; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    init();
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int flag = 1;
    for(int i = 1 ; i <= 70 ; i++, flag ^= 1){
        for(int j = 0 ; j < (1 << 19) ; j++)
            dp[flag][j] = 0;
        if(cnt[i] == 0){
            for(int j = 0 ; j < (1 << 19) ; j++){
                dp[flag][j] = dp[flag ^ 1][j];
            }
        }else{
            int m = mask(i);
            for(int j = 0 ; j < (1 << 19) ; j++){
                dp[flag][j] += (dp[flag ^ 1][j ^ m] * pow2[cnt[i] - 1]) % MOD;
                dp[flag][j] %= MOD;
                dp[flag][j] += (dp[flag ^ 1][j] * pow2[cnt[i] - 1]) % MOD;
                dp[flag][j] %= MOD;
            }
        }
    }
    printf("%lld\n", (dp[flag ^ 1][0] - 1 + MOD) % MOD);
    return 0;
}

