//#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int b[20][20];
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,1,-1,0,1,-1,0};
bool isin(int x, int y){
    return x>=0&&y>=0&&x<19&&y<19;
}
void Solve(){
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(b[i][j]==0)continue;
            for(int k=0;k<8;k++){
                int cnt=0;
                for(int l=0;l<5;l++){
                    int tx=i+dx[k]*l,ty=j+dy[k]*l;
                    cnt+=(isin(tx,ty)&&b[tx][ty]==b[i][j]);
                }
                if(cnt==5){
                    printf("%d\n%d %d\n",b[i][j],i+1,j+1);
                    return;
                }
            }
        }
    }
    puts("0");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<19;i++){
            for(int j=0;j<19;j++){
                scanf("%d",&b[i][j]);
            }
        }
        Solve();
    }
    return 0;
}
