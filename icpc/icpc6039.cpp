#include <bits/stdc++.h>
using namespace std;
int sum[100010], mx[100010];
int Solve(){
	int N;;
	scanf("%d", &N);
	memset(sum,0,sizeof(sum));
	memset(mx,0,sizeof(mx));
	for(int i=0;i<N-1;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		sum[a]+=c;
		sum[b]+=c;
		mx[a]=max(mx[a], c);
		mx[b]=max(mx[b], c);
	}
	int ans=0;
	for(int i=1;i<=N;i++){
		if(mx[i]>=sum[i]-mx[i])
			ans+=mx[i]-(sum[i]-mx[i]);
		else
			ans+=sum[i]&1;
	}
	return ans/2;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: %d\n", i, Solve());
	}
	return 0;
}
