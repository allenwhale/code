#include <bits/stdc++.h>
using namespace std;
int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}
int cnt[720720+10],a[100010],b[100010];
int ans[100010];
typedef pair<int,int> PI;
int mp[3000];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d",&N,&M);
        int total=1;
        for(int i=0;i<N;i++){
            scanf("%d%d",&a[i],&b[i]);
            mp[a[i]*17+b[i]]++;
            total=lcm(total,b[i]);
        }
        for(int i=1;i<=16;i++){
            for(int j=i;j<=16;j++){
                int h=i*17+j;
                if(mp[h])for(int k=0;k<total;k++){
                    if(k%j<i)
                        cnt[k]+=mp[h];
                }
            }
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
