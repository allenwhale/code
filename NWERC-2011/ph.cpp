#include <bits/stdc++.h>
using namespace std;
const char *NUMBER = "023456789TJQKA";
struct Card{
    int number;
    char suit;
    Card(){}
    Card(char *s){
        for(int i=1;i<=13;i++)
            if(NUMBER[i] == s[0])
                number = i;
        suit = s[1];
    }
}card[16];
int count_one(int x){
    int res = 0;
    while(x){
        res += x & 1;
        x >>= 1;
    }
    return res;
}
vector<int> can_use[13];
vector<int> decode(int x){
    vector<int> res;
    for(int i=0;i<13;i++){
        if((x >> i) & 1)
            res.push_back(card[i].number);
    }
    return res;
}
void build(){
    for(int i=0;i<(1<<13);i++){
        bool tf = false;
        int ones = count_one(i);
        auto use = decode(i);
        if(ones == 1){
            tf = true;
        }else if(ones >= 2 && ones <= 4){
            tf = true;
            for(int j=0;j<ones-1;j++){
                if(use[j] != use[j + 1])
                    tf = false;
            }
        }else if(ones == 5){
            sort(use.begin(), use.end());
            if(use[0] == use[1] && use[2] == use[3] && use[3] == use[4]){
                tf = true;
            }
            if(use[0] == use[1] && use[1] == use[2] && use[3] == use[4]){
                tf = true;
            }
        }
        if(ones >= 5 && tf == false){
            sort(use.begin(), use.end());
            tf = true;
            for(int i=0;i<ones-1;i++){
                if(use[i] + 1 != use[i + 1])
                    tf = false;
            }
        }
        if(tf){
            for(int j=0;j<13;j++)
                if((i >> j) & 1)
                    can_use[j].push_back(i);
        }
    }
} 
int dp[(1 << 13) + 10];
int dpnxt[(1 << 13) + 10];
int DP(int status){
    if(dp[status] != -1)
        return dp[status];
    if(status == 0)
        return dp[status] = 0;
    dp[status] = 100;
    int x = __builtin_ctz(status);
    //printf("x %d\n", x);
    for(int hashed : can_use[x]){
        //printf("%d\n", hashed);
        if((status & hashed) == hashed){
            int tmp = DP(status ^ hashed) + 1;
            if(dp[status] > tmp){
                dp[status] = tmp;
                dpnxt[status] = status ^ hashed;
            }
        }
    }
    return dp[status];
}
void print(int x){
    vector<string> p;
    for(int i=0;i<13;i++){
        if((x >> i) & 1)
            p.push_back(string() + NUMBER[card[i].number] + card[i].suit);
    }
    for(int i=0;i<(int)p.size();i++){
        if(i)printf(" ");
        printf("%s", p[i].c_str());
    }
    puts("");
}
void Solve(){
    char in[3];
    for(int i=0;i<13;i++){
        scanf("%s", in);
        card[i] = Card(in);
        can_use[i].clear();
    }
    build();
    memset(dp, -1, sizeof(dp));
    int ans = DP((1 << 13) - 1);
    printf("%d\n", ans);
    int status = (1 << 13) - 1;
    while(status){
        int hashed = status ^ dpnxt[status];
        print(hashed);
        status = dpnxt[status];
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
