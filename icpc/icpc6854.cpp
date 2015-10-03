#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        ll o=0,e=0;
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                int d;
                scanf("%d",&d);
                if(d==-1)continue;
                if((i+j)&1){
                    o+=d;
                }else{
                    e+=d;
                }
            }
        }
        printf("%lld\n",abs(o-e));
    }
    return 0;
}
