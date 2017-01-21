#include <bits/stdc++.h>
using namespace std;
char s[5010];
int sg[5010];
vector<pair<int, int>> cut;

int getSg(int x){
    if(x < 0)return 0;
    if(sg[x] != -1)return sg[x];
    vector<int> res;
    for(int i=0;i<x;i++){
        res.push_back(getSg(i - 1) ^ getSg(x - i - 1 - 1));
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    int ans = 0;
    for(int y : res){
        if(ans == y)ans++;
        else break;
    }
    return sg[x] = ans;
}

int main(){
    scanf("%s", s);
    int len = strlen(s), l = -1, sz = 0;
    for(int i=1;i<len-1;i++){
        if(s[i - 1] == s[i + 1]){
            if(l == -1){
                l = i, sz = 1;
            }else{
                sz++;
            }
        }else{
            if(l != -1){
                cut.push_back({l, sz});
                l = -1, sz = 0;
            }
        }
    }
    if(l != -1){
        cut.push_back({l, sz});
    }
    memset(sg, -1, sizeof(sg));
    sg[0] = 0;
    int ans = 0;
    for(auto c : cut){
        ans ^= getSg(c.second);
    }
    if(ans){
        puts("First");
        for(auto c : cut){
            for(int i=0;i<c.second;i++){
                if((ans ^ getSg(i - 1) ^ getSg(c.second - i - 1 - 1) ^ getSg(c.second)) == 0){
                    printf("%d\n", c.first + i + 1);
                    return 0;
                }
            }
        }
    }else{
        puts("Second");
    }

    return 0;
}
