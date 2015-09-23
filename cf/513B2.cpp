#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cc[] = {0, 1, 1, 2};
int find(ll x){
    ll mx = 1ll<<62;
    int cnt=0;
    while(x>=4){
        while(mx>x)mx>>=1;
        x-=mx;
        cnt++;
    }
    return cc[x]+cnt;
}
void Solve(int N, ll M, vector<int >&ans){
    if(N == 1){
        ans = {1};
        return ;
    }
    if(N == 2){
        if(M == 0) ans = {1, 2};
        else ans = {2, 1};
        return;
    }
    ll m = M>>1;
    Solve(N-1, m, ans);
    ll offset = (((M%4)+1)/2);
    int i,j;
    for(i=1,j=(M+1)/4;j>=4;i++){
        for(int k=0;k<i&&j>=4;k++){
            j -= 4;
            if(j<4)break;
        }
        if(j<4)break;
    }
    ll d, tmp=(M%4);
    if(tmp==0)d=0;
    else if(tmp==1||tmp==2)d=1;
    else d=2;
    offset = find(M/4)+d;
    ans.insert(ans.end()-offset, N);
}
int main(){
    int N;
    ll M;
    while(~scanf("%d%lld",&N,&M)){
        vector<int> ans;
        Solve(N, M-1, ans);
        for(int x: ans)
            printf("%d ", x);
        puts("");
    }
    return 0;
}
