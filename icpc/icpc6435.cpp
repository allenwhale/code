#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
typedef long long ll;
ll dp[50010][210];
int Solve(){
	int N,M,D;
	scanf("%d%d%d",&N,&M,&D);
	vector<int>A(N+1),B(M+1);
	A[0] = -1000000000;
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	for(int i=1;i<=M;i++)
		scanf("%d",&B[i]);
	vector<int> T[50010];
	for(int i=1,l=0;i<=M;i++){
		while(l<=N&&!(A[l]<=B[i]))l++;
		//printf("l = %d\n", l);
		int tl=l;
		while(tl<=N&&!(B[i]+D<=A[tl]))T[i].push_back(tl++);
	}
	for(int i=0;i<(int)T[1].size();i++)
		dp[1][i]=1;
	for(int i=2;i<=M;i++){
		ll sum=0, now=0;
		for(int j=0;j<(int)T[i].size();j++){
			while(sum<(int)T[i-1].size()&&T[i][j]>=T[i-1][now])sum+=dp[i-1][now++],sum%=MOD;
			dp[i][j]=sum;
		}
	}
	ll ans=0;
	for(int i=0;i<(int)T[M].size();i++)
		ans+=dp[M][i],ans%=MOD;
	return (int)ans;
}
int main(){
	int T;
	int c=1;
	scanf("%d",&T);
	while(T--){
		printf("Case #%d: %d\n", c++, Solve());
	}
	return 0;
}
