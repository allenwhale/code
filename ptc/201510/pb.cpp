#include <bits/stdc++.h>
using namespace std;
#define MAXN 500050
int _dp[2][MAXN+100];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		int d;
		memset(_dp,0,sizeof(_dp));
		scanf("%d",&d);
		int flag=0;
		int *dp, *odp;
		dp=&_dp[flag][MAXN/2];
		odp=&_dp[flag^1][MAXN/2];
		odp[d]=odp[-d]=1;
		for(int j=0;j<N-1;j++,flag^=1){
			scanf("%d",&d);
			memset(_dp[flag],0,sizeof(_dp[flag]));
			for(int i=-MAXN/2+d+1;i<MAXN/2-d;i++){
				dp[i]=(odp[i-d]|odp[i+d]);
			}
			swap(dp, odp);
		}
		printf("%s\n",odp[0]?"YES":"NO");
	}

	return 0;
}
