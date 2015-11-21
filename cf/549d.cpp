#include <bits/stdc++.h>
using namespace std;
char s[110][110];
int v[110][110] = {0};
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        scanf("%s",s[i]);
    int ans=0;
    for(int i=N-1;i>=0;i--){
        for(int j=M-1;j>=0;j--){
            int g=((s[i][j]=='B')?-1:1)-v[i][j];
            if(g){
                for(int k=0;k<=i;k++){
                    for(int l=0;l<=j;l++){
                        v[k][l]+=g;
                    }
                }
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
