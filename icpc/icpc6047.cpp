#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 370248451
#define C 131
ll pow_mod(ll x, ll n){
	ll res=1;
	while(n){
		if(n&1)res=(res*x)%MOD;
		x=(x*x)%MOD;
		n>>=1;
	}
	return res;
}
struct _str{
	int len;
	ll pos, rev;
	_str(int _l=0,ll _p=0,ll _r=0): len(_l), pos(_p), rev(_r){}
}str[1010];
int Solve(){
	int N;
	scanf("%d",&N);
	char s[510];
	for(int i=0;i<N;i++){
		scanf("%s", s);
		str[i].len=strlen(s);
		str[i].pos=str[i].rev=0;
		ll x=1;
		for(int j=0;j<str[i].len;j++){
			str[i].pos=(str[i].pos+s[j]*x)%MOD;
			x=(x*C)%MOD;
		}
		x=1;
		for(int j=0;j<str[i].len;j++){
			str[i].rev=(str[i].rev+s[str[i].len-j-1]*x)%MOD;
			x=(x*C)%MOD;
		}
	}
	int ans=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)continue;
			if(((str[i].pos+(pow_mod(C,str[i].len)*str[j].pos)%MOD)%MOD)==
					(((str[i].rev*pow_mod(C,str[j].len))%MOD+str[j].rev)%MOD))ans++;
		}
	}
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: %d\n", i, Solve());
	}
	return 0;
}
