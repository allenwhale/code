#include <bits/stdc++.h>
using namespace std;
int s[100010]={0};
int N,Q;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    scanf("%d",&Q);
    while(Q--){
        int d;
        scanf("%d",&d);
        printf("%d\n", (int)(lower_bound(s+1,s+N+1,d)-s));
    }
    return 0;
}
