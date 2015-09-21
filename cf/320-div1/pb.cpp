#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
ll pre[200010]={0},suf[200010]={0};

int main(){
    int N,K;
    ll X;
    scanf("%d %d %I64d",&N,&K,&X);
    for(int i=1;i<=N;i++){
        scanf("%I64d",&a[i]);
    }
    for(int i=1;i<=N;i++)
        pre[i]=pre[i-1]|a[i];
    for(int i=N;i>=1;i--)
        suf[i]=suf[i+1]|a[i];
    ll res=1;
    for(int i=0;i<K;i++){
        res*=X;
    }
    ll ans=0;
    for(int i=1;i<=N;i++){
        ans=max(ans,pre[i-1]|suf[i+1]|(a[i]*res));
    }
    printf("%I64d\n",ans);
    return 0;
}
