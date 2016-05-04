#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <sys/types.h>
#define N 100010
using namespace std;
const __int128 B[2] = {101LL, 37LL}, M[2] = {20000000089, 21000000019};
__int128 h[2][N<<1];
char s1[N<<1], s2[N<<1];
pair<__int128,__int128> gethash(int l,int r,__int128 b[2]) {
	__int128 res1 = h[0][r] - h[0][l-1]*b[0]%M[0], res2 = h[1][r] - h[1][l-1]*b[1]%M[1];
	if(res1 < 0)
		res1 += M[0];
	if(res2 < 0)
		res2 += M[1];
	return make_pair(res1, res2);
}
void build_hash(char s[],int len,int n) {
	for(int k = 0; k < 2; k++)
		for(int i = 0; i < len + n; i++)
			h[k][i+1] = (h[k][i]*B[k] + s[i]-'a')%M[k];
}
int main () {
	int T;
	scanf("%d", &T);
	h[0][0] = h[1][0] = 0;
	while(T--) {
		int n, len;
		__int128 b[2] = {1LL, 1LL};
		scanf("%d%s%s", &n, s1, s2);
		len = strlen(s1);
		for(int i = 0; i < len; i++)
			s1[i+len] = s1[i];
		for(int i = 0; i < len; i++)
			s2[i+len] = s2[i];
		for(int k = 0; k < 2; k++)
			for(int i = 0; i < n; i++)
				b[k] = b[k]*B[k]%M[k];
		build_hash(s1, len, n);
		map<pair<__int128,__int128>,long long> mp;
		for(int i = 0; i < len; i++)
			mp[gethash(i+1 , i+n ,b)]++;
		build_hash(s2, len, n);
		long long ans = 0;
		for(int i = 0; i < len; i++)
			ans += mp[gethash(i+1 , i+n ,b)];
		printf("%lld\n", ans);
	}
}
