#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned __int128 ull;
ull ed[128];
vector<ull> ans;
int ctz(ull x){
    int res = 0;
    while(!(x & 1))
        res++, x >>= 1;
    return res;
}
int size(ull x){
    int res = 0;
    while(x){
        if(x & 1) res++;
        x >>= 1;
    }
    return res;
}
void BronKerbosch(ull R, ull P, ull X){
	if(P == 0 && X == 0){
		ans.push_back(R);
		return;
	}
	ull Q = P & ~ed[ctz(P | X)];
	while(Q){
		int i = ctz(Q);
		BronKerbosch(R | (ull(1) << i), P & ed[i], X & ed[i]);
		Q &= ~(ull(1) << i); P &= ~(ull(1) << i); X |= (ull(1) << i);
	}
}
int mp[110][110];
int main(){
    memset(mp, 0, sizeof(mp));
    int M, N;
    scanf("%d%d", &M, &N);
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        mp[a][b] = mp[b][a] = 1;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mp[i][j] == 1)
                ed[i] |= (ull(1) << j);
        }
    }
    BronKerbosch(0, (ull(1) << N) - 1, 0);
    int mx = 0;
    for(auto x : ans)
        mx = max(mx, size(x));
    printf("%d\n", mx);
    return 0;
}
