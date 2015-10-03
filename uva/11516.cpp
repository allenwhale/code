#include <bits/stdc++.h>
using namespace std;

int N,M;
int s[100010];
bool check(int d){
    int n=0,cnt=0;
    while(cnt<M&&n<N){
        n=upper_bound(s+n,s+N,s[n]+d)-s;
        cnt++;
    }
    return n==N;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&M,&N);
        for(int i=0;i<N;i++)
            scanf("%d",&s[i]);
        sort(s,s+N);
        int l=0,r=s[N-1]-s[0];
        int ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;r=mid-1;
            }else{
                l=mid+1;
            }
        }
        printf("%.1f\n",ans/2.0);
    }
    return 0;
}
