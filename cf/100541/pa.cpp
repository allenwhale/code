#include <bits/stdc++.h>
using namespace std;
int p[1010];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,W;
        scanf("%d%d",&N,&W);
        for(int i=0;i<N;i++){
            scanf("%d",&p[i]);
        }
        int ans=0; 
        for(int i=0;i<N;i++){
            int num=W/p[i];
            for(int j=i+1;j<N;j++){
                ans=max(ans,num*(p[j]-p[i]));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
