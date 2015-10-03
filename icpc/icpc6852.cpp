#include <bits/stdc++.h>
using namespace std;
int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}
int cnt[720720+10],a[100010],b[100010];
int ans[100010];
typedef pair<int,int> PI;
map<PI,int>mp;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d",&N,&M);
        mp.clear();
        int total=1;
        for(int i=0;i<N;i++){
            scanf("%d%d",&a[i],&b[i]);
            mp[PI(a[i],b[i])]+=1;
            total=lcm(total,b[i]);
        }
        for(auto m: mp){
            PI p=m.first;
            int n=m.second;
            for(int i=0;i<total;i++)
                if(i%p.second<p.first)
                    cnt[i]+=n;
        }
        int r=M%total,d=M/total;
        for(int i=0;i<M&&i<total;i++){
            ans[cnt[i]]+=d+(i<r);
        }
        for(int i=0;i<=N;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
