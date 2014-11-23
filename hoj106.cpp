#include<stdio.h>
int main(){
    long long int t,n,m,k;
    scanf("%I64d",&t);
    while(t--){
        scanf("%I64d%I64d",&n,&m);
        k=m-n;
        if(m<n) n=m;
        if(m>n) printf("%I64d\n",m>=n*2 ? n*(n+1)/2+n-2 : m/2+k*(k+1)/2-2);
        if(m==n) printf("%I64d\n",m/2);
    }
}
