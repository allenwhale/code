#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> num;
vector<char> op;

ll dp[512][512][4];
bool calc[512][512];

void DP(int x, int y){
    if(calc[x][y])return;
    calc[x][y] = true;
    vector<ll> tmp;
    ll pmax, pmin, nmax, nmin;
    bool first = true;
    for(int cut = x ; cut < y ; cut++){
        DP(x, cut);
        DP(cut+1, y);
        for(auto u : dp[x][cut])
            for(auto v : dp[cut+1][y]){
                if(op[cut] == '+' || op[cut] == '?')
                    tmp.push_back(u + v);
                if(op[cut] == '-' || op[cut] == '?')
                    tmp.push_back(u - v);
                if(op[cut] == '*' || op[cut] == '?')
                    tmp.push_back(u * v);
            }
    }
    ll pmax, pmin, nmax, nmin;
    pmin = nmax = nmin = pmax = *(tmp.begin());
    for(auto u : tmp){
        if(u >= 0){
            if(pmin < 0)
                pmin = u;
            if(pmax < 0)
                pmax = u;
            pmin = min(pmin, u);
            pmax = max(pmax, u);
        } else {
            if(nmin > 0)
                nmin = u;
            if(nmax > 0)
                nmax = u;
            nmin = min(nmin, u);
            nmax = max(nmax, u);
        }
    }
    dp[x][y].push_back(pmin);
    dp[x][y].push_back(pmax);
    dp[x][y].push_back(nmin);
    dp[x][y].push_back(nmax);
}

int main(){
    int n, t;
    char c[2];
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d%s", &t, c);
        num.push_back(t);
        op.push_back(c[0]);
    }
    for(int i = 0 ; i < n ; i++){
        num.push_back(num[i]);
        op.push_back(op[i]);
    }
    for(int i = 0 ; i < (int)num.size() ; i++){
        dp[i][i][0] = num[i];
        dp[i][i][1] = num[i];
        dp[i][i][2] = num[i];
        dp[i][i][3] = num[i];
        calc[i][i] = true;
    }
    for(int i = 0 ; i < n ; i++){
        DP(i, i+n-1);
        ll _min = LLONG_MAX;
        ll _max = LLONG_MIN;
        for(auto x : dp[i][i+n-1]){
            _min = min(_min, x);
            _max = max(_max, x);
        }
        printf("%I64d%I64d", abs(_min), abs(_max));
    }
    printf("\n");
    return 0;
}
