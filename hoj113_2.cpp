#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#include<vector>
using namespace std;
typedef pair<int,int>	PI;
typedef vector<int>	VI;
#define f first
#define s second
#define pb push_back
#define it iterator
#define F(n) FO(i,n)
#define FO(i,n) FI(i,0,n)
#define FI(i,f,l) for(int i=(f),ei=(l);i<ei;i++)
#define FA(a) for(__typeof((a).begin())it=(a).begin(),ea=(a).end();\
		it!=ea;++it)
const int mv=1e5;int cv,m;
vector<PI>G[mv];
bool vs[mv],svs[mv];
int g(VI&x,int v,int d){
	svs[v]=1;
	x.pb(d);
	FA(G[v]){int w=it->f,c=it->s;
		if(!vs[w]&&!svs[w])
			g(x,w,(d+c)%m);
	}
}
int nrp[mv],nrvp[mv],nrts;
int nrdfs(int v,int p){
	nrp[v]=1,nrvp[v]=p,svs[v]=1;
	FA(G[v]){int w=it->f;
		if(!vs[w]&&!svs[w]){
			nrdfs(w,v);
			nrp[v]+=nrp[w];
		}
	}
}
PI nrdfs2(int v){
	svs[v]=1;
	PI x(0,v);
	FA(G[v]){int w=it->f;
		if(!vs[w])
			x.f=max(x.f,w!=nrvp[v]?nrp[w]:nrts-nrp[v]);
	}
	FA(G[v]){int w=it->f;
		if(!vs[w]&&!svs[w])
			x=min(x,nrdfs2(w));
	}
	return x;
}
int nr(int v){
	memset(svs,0,sizeof svs);
	nrdfs(v,v);
	nrts=nrp[v];
	memset(svs,0,sizeof svs);
	int x=nrdfs2(v).s;
	return x;
}
int f(int v=0){
	v=nr(v);
	int ans=0;
	vs[v]=1;
	set<int>s;
	s.insert(0);
	memset(svs,0,sizeof svs);
	FA(G[v]){int w=it->f,c=it->s;
		if(vs[w]==0){
			VI d;g(d,w,c%m);
			FA(d)ans=max(ans,max((*--s.end()+*it)%m,*--s.lower_bound(m-*it)+*it));
			FA(d)s.insert(*it);
		}
	}
	FA(G[v]){int w=it->f;
		if(vs[w]==0)
			ans=max(ans,f(w));
	}
	return ans;
}
int main(){
	int t;cin>>t;F(t){
		cin>>cv>>m;
		fill(G,G+cv,vector<PI>());
		F(cv-1){
			int v,w,c;cin>>v>>w>>c;v--,w--;
			G[v].pb(PI(w,c%m));
			G[w].pb(PI(v,c%m));
		}
		memset(vs,0,sizeof vs);
		printf("%i\n",f());
	}
}
