#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,M;
ll s[100010],tmp[100020];
bool check(ll x){
    memcpy(tmp,s,sizeof(s));
    int m=M,now=0;
    for(int i=0;i<N;i++)
        if(tmp[i])
            now=i;
    while(m--){
        ll r=x-now-1;
        while(r>0&&now>=0){
            ll d=min(tmp[now],r);
            r-=d,tmp[now]-=d;
            if(tmp[now]==0)
                now--;
        }
    }
    while(now>=0&&tmp[now]==0)now--;
    return now<0;
}
int main(){
    scanf("%d%d",&N,&M);
    ll l=0,r=0;
    for(int i=0;i<N;i++)
        scanf("%I64d",&s[i]),r+=s[i]+i+1;
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            ans=mid,r=mid-1;
        }else{
            l=mid+1;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
