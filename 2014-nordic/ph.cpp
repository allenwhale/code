#include <bits/stdc++.h>
using namespace std;

#define MAXN 400010
int T[MAXN], P[MAXN];
int s[MAXN];
int fail[MAXN], lenT, lenP;
void build() {
	for(int i=1, j=fail[0]=-1;i<lenT;i++) {
		while(j >= 0 && T[j + 1] != T[i])
			j = fail[j];
		if(T[j + 1] == T[i]) j++;
		fail[i] = j;
	}
}
bool find() {
	for(int i=0, j=-1;i<lenP;i++) {
		while(j >= 0 && T[j + 1] != P[i])
			j = fail[j];
		if(T[j + 1] == P[i]) j++;
		if(j == lenT - 1) {
			j = fail[j];
			return true;
		}
	}
	return false;
}
int calc(int a, int b){
    if(b > a) return b - a;
    return 360000 - (a - b);
}
int main(){
    int N;
    scanf("%d", &N);
    lenT = N;
    lenP = N * 2;
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &s[i]);
    }
    sort(s, s + N);
    for(int i = 0 ; i < N ; i++){
        P[i] = P[i + N] = calc(s[i], s[(i + 1) % N]);
    }
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &s[i]);
    }
    sort(s, s + N);
    for(int i = 0 ; i < N ; i++){
        T[i] = calc(s[i], s[(i + 1) % N]);
    }
    build();
    if(find())printf("possible\n");
    else printf("impossible\n");

    return 0;
}
