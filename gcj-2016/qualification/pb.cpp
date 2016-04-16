#include <bits/stdc++.h>
using namespace std;
char in[110];
int A[110];
int Solve(){
    scanf("%s", in);
    int N = strlen(in);
    for(int i=0;i<N;i++)
        A[i] = in[i] == '-';
    int flag = 1, cnt = 0;
    for(int i=N-1;i>=0;i--){
        if(A[i] == flag){
            cnt++;
            flag ^= 1;
        }
    }
    return cnt;
}
int Solve2(){
    scanf("%s", in);
    int N = strlen(in);
    for(int i=0;i<N;i++)
        A[i] = in[i] == '-';
    A[N] = 0;
    int cnt = 0;
    for(int i=0;i<N;i++)
        cnt += A[i] != A[i+1];
    return cnt;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: %d\n", t, Solve());
    }
    return 0;
}
