#include <bits/stdc++.h>
using namespace std;

int P, K, N;
int sg[1010];
int c[1010];

int getSg(int x){
    if(sg[x] != -1)return sg[x];
    vector<int> res;
    for(int i=0;i<=K&&i<x;i++){
        if(x - i - c[x - i - 1] >= 0){
            res.push_back(getSg(x - i - c[x - i - 1]));
        }
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

void Solve(){
    int ans = 0;
    for(int i=0;i<P;i++){
        memset(sg, -1, sizeof(sg));
        sg[0] = 0;
        scanf("%d", &N);
        for(int j=0;j<N;j++)
            scanf("%d", &c[j]);
        //printf("%d\n", getSg(2));
        //for(int i=0;i<=N;i++)
            //printf("%d %d\n", i, getSg(i));
        ans ^= getSg(N);
    }
    if(!ans)printf("Bob will win.\n");
    else printf("Alice can win.\n");
}

int main(){
    while(~scanf("%d%d", &P, &K))
        Solve();
    return 0;
}
