#include <bits/stdc++.h>
using namespace std;
#define A 29
#define M 370248451
char s[500010];
typedef long long ll;
ll h[500010];
ll pow_mod(ll x, int n){
	ll res=1;
	while(n){
		if(n&1)res=(res*x)%M;
		x=(x*x)%M;
		n>>=1;
	}
	return res;
}
bool equal(int l1,int l2,int r1,int r2){
	ll tl=(M+h[l2]-(h[l1-1]*pow_mod(A,l2-l1+1))%M)%M,tr=(M+h[r2]-(h[r1-1]*pow_mod(A,r2-r1+1))%M)%M;
	return (tl)%M==tr;
}
int Solve(){
	scanf("%s", s+1);
	h[0]=0;
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
		h[i]=(h[i-1]*A+s[i]-'A')%M;
	int l=1,r=len;
	int ans=0;
	while(l<r){
		int tr=r;
		while((r-tr+1)+l-1<tr&&!equal(l,l+r-tr,tr,r)){
			tr--;
		}
		ans++;
		if((r-tr+1)+l-1<tr&&equal(l,l+r-tr,tr,r)){
			ans++;
			l=l+r-tr+1;
			r=tr-1;
		}else{
			break;
		}
	}
	if(l==r)ans++;
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	int c=1;
	while(T--){
		printf("Case #%d: %d\n", c++, Solve());
	}
	return 0;
}
