#include <bits/stdc++.h>
using namespace std;
int c[20];
int N,L,R,X;
bool check(int k){
    int sum=0, mx=0, mn=10000000;
    for(int i=0;i<N;i++){
        if((k>>i)&1){
            sum+=c[i];
            mn=min(mn, c[i]);
            mx=max(mx, c[i]);
        }
    }
    return (L<=sum&&sum<=R)&&(mx-mn)>=X;
}
int main(){
    scanf("%d%d%d%d",&N,&L,&R,&X);
    for(int i=0;i<N;i++)
        scanf("%d",&c[i]);
    int ans=0;
    for(int i=0;i<(1<<N);i++){
        ans+=check(i);
    }
    printf("%d\n", ans);
    return 0;
}
