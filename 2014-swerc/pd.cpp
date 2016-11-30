#include <bits/stdc++.h>
using namespace std;

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
    int PreTest(){
        int ans = 0;
        for(int i=0;i<Nx;i++){
            if(mx[i] != -1) continue;
            for(int j : vc[i]){
                if(my[j] != -1) continue;
                mx[i] = j, my[j] = i;
                ans++;
                break;
            }
        }
        return ans;
    }
	int Solve(){
		mx = vector<int>(Nx+1, -1);
		my = vector<int>(Ny+1, -1);
		visy = vector<int>(Ny+1, 0);
		int ans = PreTest();
		for(int i=0;i<Nx;i++){
			if(mx[i] == -1){
				fill(visy.begin(), visy.end(), 0);
				ans += Match(i);
			}
		}
		return ans;
	}
};
int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    BiMatch bi(N, N);
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        bi.add(a, b);
    }
    printf("%s\n", bi.Solve() == N ? "YES" : "NO");
    return 0;
}
