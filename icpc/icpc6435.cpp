#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
typedef long long ll;
ll dp[50010][510];
int N,M,D;
vector<int>A,B;
int dfs(int x,int y){
	while(x<N&&B[y]-A[x]>D)x++;
	while(y<M&&A[x]-B[y]>D)y++;
	ll &res=dp[x][A[x]-B[y]+100];
	if(x==N||y==M)return res=1;
	if(res!=-1)return res;
	res=0;
	if(A[x]+D>B[y])res+=dfs(x,y+1);
	if(B[y]+D>A[x])res+=dfs(x+1,y);
	res%=MOD;
	return res;
}
int Solve(){
	scanf("%d%d%d",&N,&M,&D);
	A=B=vector<int>(max(N,M)+1);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<M;i++)
		scanf("%d",&B[i]);
	return dfs(0,0);
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
