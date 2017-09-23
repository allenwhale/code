#include <bits/stdc++.h>
using namespace std;

int ans[20], cnt[20];

#define lb(x) ((x) & (-(x)))

int cnt_one(int x){
    int res = 0;
    while(x){
        res++;
        x -= lb(x);
    }
    return res;
}

typedef long long ll;
#define MOD 59604644783353249ll

void Solve(){
    unordered_map<ll, vector<int>> mp;
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0 ; i < N ; i++){
        ans[i] = 0;
        for(int j = 0 ; j < M ; j++){
            int x;
            scanf("%1d", &x);
            ans[i] |= (x << j);
        }
        scanf("%d", &cnt[i]);
    }
    for(int i = 0 ; i < (1 << (M / 2)) ; i++){
        bool bad = false;
        ll h = 0;
        for(int j = 0 ; j < N ; j++){
            int tmp = cnt[j] - (M / 2 - cnt_one((ans[j] & ((1 << (M / 2)) - 1)) ^ i));
            if(tmp < 0){
                bad = true;
                break;
            }
            h = (h * 31 + tmp) % MOD;
        }
        if(!bad){
            mp[h].push_back(i);
        }
    }
    int ans_cnt = 0;
    int all_ans = 0;
    for(int i = 0 ; i < (1 << (M - M / 2)) ; i++){
        bool bad = false;
        ll h = 0;
        for(int j = 0 ; j < N ; j++){
            int tmp = M - M / 2 - cnt_one((ans[j] >> (M / 2)) ^ i);
            if(tmp > cnt[j]){
                bad = true;
                break;
            }
            h = (h * 31 + tmp) % MOD;
        }
        if(bad)continue;
        if(mp.find(h) != mp.end()){
            ans_cnt += mp[h].size();
            if(mp[h].size() == 1){
                all_ans = mp[h][0] | (i << (M / 2));
            }
            //for(int x : mp[h]){
                //int tmp_ans = x | (i << (M / 2));
                //bool ok = true;
                //for(int j = 0 ; j < N ; j++){
                    //if(M - cnt_one(tmp_ans ^ ans[j]) != cnt[j]){
                        //ok = false;
                        //break;
                    //}
                //}
                //if(ok){
                    //ans_cnt++;
                    //all_ans = tmp_ans;
                //}
            //}
        }
    }
    if(ans_cnt != 1)
        printf("%d solutions\n", ans_cnt);
    else{
        for(int i = 0 ; i < M ; i++)
            printf("%d", (all_ans >> i) & 1);
        printf("\n");
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
}
