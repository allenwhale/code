#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b,int n){
    int ta=a,tb=b;
    bool vis[10]={0};
    for(int i=0;i<5;i++){
        int aa=a%10,bb=b%10;
        if(vis[aa])return false;
        vis[aa]=true;
        if(vis[bb])return false;
        vis[bb]=true;
        a/=10;b/=10;
    }
    if(a==0&&b==0){
        printf("%05d / %05d = %d\n", tb,ta,n);
    }
    return a==0&&b==0;
}
void Solve(int n){
    int ans=0;
    for(int i=1234;i<100000;i++){
        int j=i*n;
        ans+=check(i,j,n);
    }
    if(ans==0)printf("There are no solutions for %d.\n",n);
}
int main(){
    int N;
    bool f=true;

    while(~scanf("%d",&N)&&N){
        if(!f)puts("");
        f=false;
        Solve(N);
    }
    return 0;
}

