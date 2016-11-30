#include <bits/stdc++.h>
using namespace std;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};
unordered_map<pair<int, int>, int, pair_hash> mp;
int find(int n, int x){
    int ans = 0;
    for(int i=x;i<=n;i+=x){
        int nn = n - i;
        if(nn == 0){
            //printf("a %d 0 0 \n", i/x);
            ans++;
            continue;
        }
        //ans += (nn / ((x + 1) * (x + 2))) + (nn % ((x+1)*(x+2))==0);
        //continue;
        auto pi = make_pair(nn, x+1);
        if(mp.find(pi) != mp.end()){
            ans += mp[pi];
            continue;
        }
        int tmp = 0;
        for(int j=0;j<=nn;j+=(x+1)){
            int nnn = nn - j;
            if(nnn % (x + 2) == 0){
                //printf("a %d %d %d\n", i / x, j / (x +1), nnn / (x +2));
                tmp++;
            }
        }
        ans+=tmp;
        mp[pi] = tmp;
    }
    return ans;
}
int Solve(){
    int N, D;
    scanf("%d%d", &N, &D);
    int ans = 0;
    for(int i=D;i<=N;i+=D){
        //printf("%d %d\n", i, find(N, i));
        ans += find(N, i);
    }
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: %d\n", t, Solve());
    }
    return 0;
}
