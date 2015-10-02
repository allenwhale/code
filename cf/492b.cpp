#include <bits/stdc++.h>
using namespace std;
int s[1010];
int main(){
    int N,L;
    scanf("%d%d",&N,&L);
    for(int i=0;i<N;i++)
        scanf("%d",&s[i]);
    sort(s,s+N);
    double ans=max(s[0],L-s[N-1]);
    for(int i=0;i<N-1;i++)
        ans=max(ans,(s[i+1]-s[i])/2.0);
    printf("%.9f\n", (double)ans);
    return 0;
}
