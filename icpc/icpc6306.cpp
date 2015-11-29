#include <bits/stdc++.h>
using namespace std;
int s[1010];
bool dp[1010*500];
void Solve(){
    int mind=1000000000,id=-1, mins, ming;
    for(int k=0;k<3;k++){
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        int N;
        scanf("%d",&N);
        int sum=0;
        for(int i=0;i<N;i++){
            scanf("%d",&s[i]);
            sum+=s[i];
        }
        for(int i=0;i<N;i++){
            for(int j=sum/2;j>=s[i];j--){
                dp[j]|=dp[j-s[i]];
            }
        }
        int delta;
        for(int i=sum/2;;i--){
            if(dp[i]){
                delta=sum-i-i;
                break;
            }
        }
        if(delta<mind){
            mind=delta;
            mins=sum;
            ming=(sum-delta)>>1;
            id=k;
        }else if(delta==mind&&sum>mins){
            mins=sum;
            ming=(sum-delta)>>1;
            id=k;
        }
    }
    printf("%c %d %d\n", 'A'+id, ming, mins-ming);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        Solve();
    }
}
