#include <bits/stdc++.h>
using namespace std;
int v[100]={0};
int h[100]={0};
int ans[100000]={0};
int main(){
    int N;
    scanf("%d",&N);
    int a,b;
    for(int i=1;i<=N*N;i++){
        scanf("%d%d",&a,&b);
        if(!h[a]&&!v[b]){
            h[a]=v[b]=1;
            ans[i]=1;
        }
    }
    for(int i=1;i<=N*N;i++)
        if(ans[i])printf("%d ",i);
    puts("");
    return 0;
}
