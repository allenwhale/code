#include <bits/stdc++.h>
using namespace std;
int s[100010 * 2];
typedef pair<int, int> PII;
#define lb(x) ((x) & (-(x)))
PII pos[100010];
int bit[200010];
void update(int x, int v){
    while(x < 200010){
        bit[x] += v;
        x += lb(x);
    }
}
int query(int x){
    int res = 0;
    while(x){
        res += bit[x];
        x -= lb(x);
    }
    return res;
}
int main(){
    freopen("B.IN", "r", stdin);
    int N;
    scanf("%d", &N);
    for(int i = 1 ; i <= N * 2 ; i++){
        scanf("%d", &s[i]);
        pos[s[i]].first = pos[s[i]].second;
        pos[s[i]].second = i;
    }
    memset(bit, 0, sizeof(bit));
    int ans = 0;
    for(int i = 1 ; i <= N * 2 ; i++){
        if(i == pos[s[i]].first){//in
            update(pos[s[i]].second, 1);
            ans += query(pos[s[i]].second - 1) - query(pos[s[i]].first);
        }else{//out
            update(pos[s[i]].second, -1);
        }
    }
    printf("%d\n", ans);
    return 0;
}
