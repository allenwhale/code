#include <bits/stdc++.h>
using namespace std;

/*
 * Maximal Clique
 * store maximal cliques in ans
 * __builtin_ctz: returns the number of trailing 0-bits
 * R = 0, P = all, X = 0
 */
typedef bitset<80> ull;
int ctz(const ull &x){
    for(int i = 0 ;; i++){
        if(x[i])return i;
    }
    return -1;
}
ull ed[80];
vector<ull> ans;
int mx = 0;
int cnt = 0;
void BronKerbosch(ull R, ull P, ull X){
    if(cnt >= 100000)return;
	if(P == 0 && X == 0){
        int res = R.count();
        if(res == mx)cnt++;
        else if(res > mx)mx = res, cnt = 1;
        //printf("%d\n", cnt++);
        //printf("%d\n", mx);
		//ans.push_back(R);
		return;
	}
	ull Q = P & ~ed[ctz(P | X)];
	//while(Q.any()){
		//int i = ctz(Q);
    for(int i = 0 ; i < 75 ; i++){
        if(!Q[i])continue;
        ull tmp;
        tmp.set(i);
		BronKerbosch(R | tmp, P & ed[i], X & ed[i]);
		P &= ~(tmp); X |= (tmp);
	}
}
int main(){
    int K, N;
    scanf("%d%d", &K, &N);
    if(N >= K * 5){
        printf("possible\n");
        return 0;
    }
    ull P;
    for(int i = 0 ; i < N ; i++){
        P.set(i);
        for(int j = 0 ; j < N ; j++){
            if(i != j)
                ed[i].set(j);
        }
    }
    for(int i = 0 ; i < N ; i++){
        int x;
        scanf("%d", &x);
        while(x--){
            int t;
            scanf("%d", &t);
            t--;
            ed[i].reset(t);
            ed[t].reset(i);
        }
    }
    BronKerbosch(ull(), P, ull());
    if(mx >= K)
        printf("possible\n");
    else
        printf("impossible\n");
    return 0;
}
