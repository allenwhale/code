#include <bits/stdc++.h>
using namespace std;
#define MAX_PRIME 40000

bool isPrime[MAX_PRIME];
vector<int> primes;

void makePrime(){
    memset(isPrime, true, sizeof(isPrime));
    for(int i=2;i<MAX_PRIME;i++){
        if(isPrime[i])primes.push_back(i);
        for(int p : primes){
            if(i * p >= MAX_PRIME)break;
            isPrime[i * p] = false;
            if(i % p == 0)break;
        }
    }
}
struct BiMatch{
	int Nx, Ny;
	vector<vector<int> > vc;
	vector<int> mx, my;
	vector<int> visy;

	BiMatch(int _x=0, int _y=0): Nx(_x), Ny(_y), vc(vector<vector<int> >(Nx+1)){}

	void add(int x, int y){
		vc[x].push_back(y);
	}

	bool Match(int x){
		for(int y:vc[x]){
			if(!visy[y]){
				visy[y] = 1;
				if(my[y] == -1 || Match(my[y])){
					mx[x] = y, my[y] = x;
					return true;
				}
			}
		}
		return false;
	}
	int Solve(){
		mx = vector<int>(Nx+1, -1);
		my = vector<int>(Ny+1, -1);
		visy = vector<int>(Ny+1, 0);
		int ans = 0;
		for(int i=0;i<Nx;i++){
			if(mx[i] == -1){
				fill(visy.begin(), visy.end(), 0);
				ans += Match(i);
			}
		}
		return ans;
	}
};

int N, M;
int A[110];
int cnt[2];
vector<pair<int, int>> D[110];

vector<pair<int, int>> factor(int idx, int x){
    vector<pair<int, int>> res;
    for(int p : primes){
        if(p * p > x)break;
        while(x % p == 0){
            res.push_back({p, cnt[idx]++});
            x /= p;
        }
    }
    if(x > 1)res.push_back({x, cnt[idx]++});
    return res;
}

int main(){
    makePrime();
    scanf("%d%d", &N, &M);
    for(int i=0;i<N;i++){
        scanf("%d", &A[i]);
        D[i] = factor(i & 1, A[i]);
    }
    BiMatch m(cnt[0], cnt[1]);
    for(int i=0;i<M;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        if(x & 1)swap(x, y);
        for(auto p1 : D[x]){
            for(auto p2 : D[y]){
                if(p1.first == p2.first){
                    m.add(p1.second, p2.second);
                }
            }
        }
    }
    printf("%d\n", m.Solve());
    return 0;
}
