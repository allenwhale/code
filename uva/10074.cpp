#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int mp[110][110];
int h[110][110];
int l[110][110];
int r[110][110];
typedef pair<int,int> PI;
int Solve(){
    int N,M;
    scanf("%d%d",&N,&M);
    if(N==0&&M==0)return -1;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            scanf("%d",&mp[i][j]);
    memset(h,0,sizeof(h));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            h[i][j]=(mp[i][j]==0)?h[i-1][j]+1:0;
    for(int i=1;i<=N;i++){
        h[i][0]=h[i][M+1]=-1;
        for(int j=1;j<=M;j++)
            l[i][j]=r[i][j]=j;
        for(int j=1;j<=M;j++)
            while(h[i][j]<=h[i][l[i][j]-1])l[i][j]=l[i][l[i][j]-1];
        for(int j=M;j>=1;j--)
            while(h[i][j]<=h[i][r[i][j]+1])r[i][j]=r[i][r[i][j]+1];
    }
    int ans=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            ans=max(ans, h[i][j]*(r[i][j]-l[i][j]+1));
    return ans;
}
int main(){
    int ans;
    while((ans=Solve()) != -1){
        printf("%d\n", ans);
    }
}
