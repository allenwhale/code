#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int a,b,w;
	Edge(int _a=0,int _b=0,int _w=0):a(_a),b(_b),w(_w){}
	bool operator < (const Edge &n) const {
		return n.w>w;
	}
};
int f[110], v[110];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void U(int a,int b){
	f[find(a)]=find(b);
}
int Solve(){
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<=N;i++)v[i]=0,f[i]=i;
	for(int i=0;i<K;i++){
		int p;
		scanf("%d",&p);
		v[p]=1;
	}
	vector<Edge> vc(M);
	for(int i=0;i<M;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		vc[i]=Edge(a,b,w);
	}
	sort(vc.begin(), vc.end());
	int r=N-K, ans=0;
	for(int i=0;i<(int)vc.size()&&r;i++){
		Edge e=vc[i];
		int tmp=v[find(e.a)]|v[find(e.b)];
		if(find(e.a)!=find(e.b)&&!(v[find(e.a)]==1&&v[find(e.b)]==1)){
			U(e.a,e.b);
			v[find(e.a)]|=tmp;
			v[find(e.b)]|=tmp;
			r--;
			ans+=e.w;
		}
	}
	return ans;
}
int main(){
	int T;
	scanf("%d", &T);
	int c=1;
	while(T--){
		printf("Case #%d: %d\n", c++, Solve());
	}
	return 0;
}
