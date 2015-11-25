#include <bits/stdc++.h>
using namespace std;
int w[20],b[20],cnt[3],p[20];
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&b[i]);
        cnt[b[i]]++;
    }
    int odd=0,even=0;
    for(int i=0;i<M;i++){
        scanf("%d",&p[i]);
        if(i&1)odd+=p[i];
        else even+=p[i];
    }
    int ans1=100000,ans2=100000;
    if(even==cnt[0]){
        memcpy(w,b,sizeof(b));
        ans1=0;
        int now=0;
        for(int i=0;i<M;i++){
            for(int k=0;k<p[i];k++){
                if(w[now]!=(i&1)){
                    int j;
                    for(j=now+1;j<N;j++){
                        if(w[j]==(i&1))break;
                    }
                    for(;j>=now+1;j--){
                        swap(w[j],w[j-1]);
                        ans1++;
                    }
                }
                now++;
            }
        }
    }
    if(odd==cnt[0]){
        memcpy(w,b,sizeof(b));
        ans2=0;
        int now=0;
        for(int i=0;i<M;i++){
            for(int k=0;k<p[i];k++){
                if(w[now]!=!(i&1)){
                    int j;
                    for(j=now+1;j<N;j++){
                        if(w[j]==!(i&1))break;
                    }
                    for(;j>=now+1;j--){
                        swap(w[j],w[j-1]);
                        ans2++;
                    }
                }
                now++;
            }
        }
    }
    printf("%d\n", min(ans1,ans2));
    return 0;
}


