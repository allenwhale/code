#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while((a%=b)&&(b%=a));
    return a+b;
}
int lcm1(int a,int b){
    return (a/gcd(a,b))*b;
}
int cnt[7207200];
int ans[1000010];
typedef pair<int,int> PI;
int mp[3000];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d",&N,&M);
        int total=1;
        for(int i=0;i<400;++i)mp[i]=0;
        for(int i=0;i<N;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            mp[a*17+b]++;
            total=lcm1(total,b);
        }
        memset(cnt,0,sizeof(cnt));
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
        memset(ans,0,sizeof(ans));
        for(int i=0;i<M&&i<total;i++){
            ans[cnt[i]]+=d+(i<r);
        }
        for(int i=0;i<=N;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
