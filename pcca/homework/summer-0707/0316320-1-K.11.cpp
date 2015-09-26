#include <bits/stdc++.h>
using namespace std;
char name[100];
char b[20][20];
int w[20][20];
int dx[]={0,0,0,1,-1};
int dy[]={0,1,-1,0,0};
void step(int x, int y){
    for(int i=0;i<5;i++){
        w[dx[i]+x][dy[i]+y]^=1;
    }
}
int Solve(){
    int ans=10000;
    for(int i=0;i<(1<<10);i++){
        int cnt=0;
        for(int x=1;x<=10;x++){
            for(int y=1;y<=10;y++){
                w[x][y]=(b[x][y]=='#')?0:1;
            }
        }
        for(int j=1;j<=10;j++){
            if((i>>(j-1))&1)cnt++,step(1,j);
        }
        for(int x=2;x<=10;x++){
            for(int y=1;y<=10;y++){
                if(w[x-1][y])cnt++,step(x,y);
            }
        }
        int tmp=0;
        for(int x=1;x<=10;x++)
            for(int y=1;y<=10;y++)
                tmp+=w[x][y];
        if(tmp==0)ans=min(ans,cnt);
    }
    return ans<=1000?ans:-1;
}
int main(){
    while(~scanf("%s",name)&&strcmp(name, "end")){
        for(int i=1;i<=10;i++){
            scanf("%s",b[i]+1);
        }
        int ans=Solve();
        printf("%s %d\n",name,ans);
    }
    return 0;   
}

