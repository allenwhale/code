#include <bits/stdc++.h>
using namespace std;
bool Solve(){
    int N;
    scanf("%d",&N);
    int x1,y1,x2,y2,z;
    scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&z);
    x1+=(1<<(N-1))-1;
    x2+=(1<<(N-1))-1;
    int up1=(y1+1)/2,down1=y1-up1;
    int up2=(y2+1)/2,down2=y2-up2;
    int o1=y1/2!=up1,o2=y2/2!=up2;
    x1>>=up1;x1<<=down1;
    x2>>=up2;
    for(int i=0;i<down2;i++)
        x2=x2*2+1;
    int ans=o1^o2;
    if(ans){
        if(!o1)x1>>=1;
        else x2>>=1;
    }
    while(x1!=x2){
        x1>>=1;
        x2>>=1;
        ans+=2;
    }
    return ans>z;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        printf("%s\n", Solve()?"YES":"NO");
    }
    return 0;
}
