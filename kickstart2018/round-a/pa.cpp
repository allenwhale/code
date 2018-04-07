#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll p10[18];

ll down(ll N){
    char s[20];
    int len = sprintf(s, "%lld", N);
    for(int i = 0 ; i < len ; i++)
        s[i] -= '0';
    ll ans = 0;
    for(int i = 0 ; i < len ; i++){
        if(s[i] % 2){
            if(i == len - 1){
                ans += 1;
                s[i]--;
            }else{ 
                ans += p10[len - 2 - i] * (s[i + 1] + 1);
                s[i]--;
                s[i + 1] = 9;
            }
        } 
    }
    
    //printf("dd = ");
    //for(int i = 0 ; i < len ; i++)
        //printf("%d", s[i]);
    //puts("");
    return ans;
}

ll toi(int s[], int x){
    ll n = 0;
    for(int i = 0 ; i < x ; i++)
        n += s[i] * p10[i];
    return n;
}

ll up(ll N){
    int s[20] = {0}, len = 0;
    while(N){
        s[len++] = N % 10;
        N /= 10;
    }
    ll ans = 0;
    for(int i = 0 ; i < len ; i++){
        if(s[i] == 10){
            s[i] = 0;
            s[i + 1]++;
            if(i == len - 1)len++;
        }
        if(s[i] % 2){
            if(i == 0){
                ans += 1;
                s[i] += 1;
            }else{
                //ans += p10[i - 1] * (10 - s[i - 1]);
                ans += p10[i] - toi(s, i);
                //printf("aaa %d : %lld %lld\n", i, p10[i], toi(s, i));
                //s[i - 1] = 0;
                for(int j = 0 ; j < i ; j++)
                    s[j] = 0;
                s[i]++;
            }
            if(s[i] == 10){
                if(i == len - 1)len++;
                s[i] = 0;
                s[i + 1]++;
            }
        }
    //for(int i = len - 1 ; i >= 0 ; i--)
        //printf("%d", s[i]);
    //puts("");
    }
    //printf("up = ");
    //for(int i = len - 1 ; i >= 0 ; i--)
        //printf("%d", s[i]);
    //puts("");
    return ans;
}


bool check(ll x){
    while(x){
        if(x % 2)return false;
        x /= 10;
    }
    return true;
}

ll brute(ll N){
    ll ans = LLONG_MAX;
    ll x;
    for(ll i = 0 ; i < N * 10 + 10 ; i++){
        if(check(i)){
            ans = min(ans, abs(i - N));
            if(ans == abs(i - N))
                x = i;
        }
    }
    //printf("b = %lld\n", x);
    return ans;
}

void Solve(){
    ll N;
    scanf("%lld", &N);
    ll ans1 = down(N), ans2 = up(N);
    printf("%lld\n", min(ans1, ans2));
    //printf("%d\n", min(ans1, ans2) == brute(N));
}


int main(){
    p10[0] = 1;
    for(int i = 1 ; i < 18 ; i++)
        p10[i] = p10[i - 1] * 10;
    int T;
    scanf("%d", &T);
    for(int t = 1 ; t <= T ; t++){
        printf("Case #%d: ", t);
        Solve();
    }
    return 0;
}
