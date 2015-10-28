#include <bits/stdc++.h>
using namespace std;
vector<int> vc[20010];
int d[20010];
int N;
void dfs(int x, int p, int &ans){
	int tmp=0;
	for(int i=0;i<(int)vc[x].size();i++){
		if(vc[x][i]==p)continue;
		dfs(vc[x][i], x, ans);
		d[x] += d[vc[x][i]];
	}
	for(int i=0;i<(int)vc[x].size();i++){
		if(vc[x][i]==p)continue;
		tmp+=(d[x]-d[vc[x][i]])*d[vc[x][i]];
	}
	tmp/=2;
	tmp+=d[x]*(N-1-d[x]);
	d[x]++;
	ans=max(ans,tmp);
	return ;
}
void Solve(){
	scanf("%d",&N);
	memset(d,0,sizeof(d));
	for(int i=0;i<=N;i++)
		vc[i].clear();
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	int ans=0;
	dfs(1,1,ans);
	printf("%d\n", ans);
}
int main(){
	int T;
	scanf("%d",&T);
	int c=1;
	while(T--){
		printf("Case #%d: ", c++);
		Solve();
	}
	return 0;
}
