#include <bits/stdc++.h>
using namespace std;
int mp[30][30];
int v[30];
int dp[(1<<20)+10];
vector<int>ans;
int N;
int _lg(int x){
	int res=0;
	while(x!=1)
		res++,x>>=1;
	return res;
}
void dfs(int sta,int l){
	if(dp[sta]!=-1)return;
	if(l==1)ans.push_back(_lg(sta));
	dp[sta]=1;
	int sum[30]={0};
	for(int i=0;i<N;i++){
		if((sta>>i)&1)for(int j=0;j<N;j++){
			if((sta>>j)&1)sum[i]+=mp[i][j];
		}
	}
	for(int i=0;i<N;i++){
		if(sum[i]>0)
			dfs(sta^(1<<i),l-1);
	}
}
void Solve(){
	scanf("%d",&N);
	memset(dp,-1,sizeof(dp));
	ans.clear();
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&mp[i][j]);
	dfs((1<<N)-1, N);
	sort(ans.begin(), ans.end());
	if((int)ans.size()==0)printf("0");
	for(auto v: ans)
		printf("%d ",v+1);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		Solve();
	}
	return 0;
}
