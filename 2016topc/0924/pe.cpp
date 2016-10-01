#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000010
ll mindiv[MAXN], phi[MAXN];
void genphi(){
	for(int i=1;i<MAXN;i++)
		mindiv[i] = i;
	for(int i=2;i*i<MAXN;i++)
		if(mindiv[i] == i)
			for(int j=i*i;j<MAXN;j+=i)
				mindiv[j] = i;
	phi[1] = 1;
	for(int i=2;i<MAXN;i++){
		phi[i] = phi[i / mindiv[i]];
		if((i / mindiv[i]) % mindiv[i] == 0)
			phi[i] *= mindiv[i];
		else phi[i] *= (mindiv[i] - 1);
	}
}
ll dp[MAXN];
int main(){
    genphi();
    dp[1] = 1;
    dp[2] = 5;
    for(int i=3;i<MAXN;i++){
        dp[i] = dp[i-1] + phi[i] * 3;
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        if(N == 1)printf("1\n");
        else{
            printf("%lld/2\n", dp[N]);
        }
    }
}
