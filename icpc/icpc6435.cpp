#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
typedef long long ll;
ll dp[50010][210];
int N,M,D;
vector<int>A(N+1),B(M+1);
int dfs(int x,int y){
	while(x<N&&B[y]-A[x]>D)x++;
	while(y<M&&A[x]-B[y]>D)y++;
	ll &res=dp[x][A[x]-B[y]+100];
	if(x==N||y==M)return res=0;
	res=0;
	if(A[x]+D>B[y])res+=dfs(x,y+1);
	if(B[y]+D>A[x])res+=dfs(x+1,y);
	return res;
}
int Solve(){
	scanf("%d%d%d",&N,&M,&D);
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
