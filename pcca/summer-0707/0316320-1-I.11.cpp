#include <bits/stdc++.h>
using namespace std;
int s[100];
void Solve(int N, int M){
    for(int i=0;i<N;i++)
        s[i] = i+1;
    int ans = 0;
    do{
        int sum = 0;
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                int mn = 10000000;
                for(int k=i;k<=j;k++){
                    mn = min(mn, s[k]);
                }
                sum += mn;
            }
        }
        ans = max(ans, sum);
    }while(next_permutation(s,s+N));
    sort(s,s+N);
    int cnt = 0;
    do{
        int sum = 0;
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                int mn = 10000000;
                for(int k=i;k<=j;k++){
                    mn = min(mn, s[k]);
                }
                sum += mn;
            }
        }
        if(sum == ans){
            cnt++;
        }
        if(cnt == M){
            for(int i=0;i<N;i++)
                printf("%d ",s[i]);
            puts("");
            return ;
        }
    }while(next_permutation(s, s+N));
}
void test(){
    for(int i=1;i<=64*2;i++){
        printf("%d ",i);
        Solve(8,i);
        if(i%4==0)puts("");
    }
}
int main(){
    int N, M;
    test();
    while(~scanf("%d%d",&N,&M)){
        Solve(N, M);
    }
    
    return 0;
}
