#include <bits/stdc++.h>
using namespace std;

struct KM{
#define FF first
#define SS second
#define INF 0x3f3f3f3f
	typedef pair<int, int> PI;
	int N;
	vector<vector<int> >mp;
	vector<int> visx, visy;
	vector<int> lx, ly, slack;
	vector<int> mx, my;
	KM(int n): N(n), mp(vector<vector<int> >(N+1, vector<int>(N+1, 0))) {}
	void add(int x, int y, int w){
		mp[x][y] = w;
	}

	bool Match(int x){
		visx[x] = 1;
		for(int i=0;i<N;i++){
			int y = i;
			if(visy[y]) continue;
			int tmp = lx[x] + ly[y] - mp[x][y];
			if(tmp == 0){
				visy[y] = 1;
				if(my[y] == -1 || Match(my[y])){
					mx[x] = y, my[y] = x;
					return true;
				}
			}else{
				slack[y] = min(slack[y], tmp);
			}
		}
		return false;
	}

	int Solve(){
		mx = vector<int>(N+1, -1);
		my = vector<int>(N+1, -1);
		lx = vector<int>(N+1, -INF);
		ly = vector<int>(N+1, 0);
		slack = vector<int>(N+1, INF);
		visx = vector<int>(N+1, 0);
		visy = vector<int>(N+1, 0);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				lx[i] = max(lx[i], mp[i][j]);
		for(int i=0;i<N;i++){
			fill(slack.begin(), slack.end(), INF);
			while(true){
				fill(visx.begin(), visx.end(), 0);
				fill(visy.begin(), visy.end(), 0);
				if(Match(i)) break;
				int d = INF;
				for(int j=0;j<N;j++)
					if(!visy[j]) d = min(d, slack[j]);
				if(d == INF)break;
				for(int i=0;i<N;i++)
					if(visx[i]) lx[i] -= d;
				for(int i=0;i<N;i++)
					if(visy[i]) ly[i] += d;
					else slack[i] -= d;
			}
		}
		int res = 0;
		for(int i=0;i<N;i++)
			if(mx[i] != -1)
				res += mp[i][mx[i]];
		return res;
	}
};

int pos[110], strength[2][110];

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i=0;i<N;i++){
        char p[10];
        scanf("%s%d", p, &strength[0][i]);
        pos[i] = p[0] == 'A';
    }
    for(int i=0;i<M;i++){
        scanf("%d", &strength[1][i]);
    }
    KM km1(max(N, M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(pos[i]){//ATK
                if(strength[1][j] >= strength[0][i]){
                    km1.add(i, j, strength[1][j] - strength[0][i]);
                }
            }
        }
    }
    int ans = km1.Solve();
    if(M > N){
        KM km2(max(N, M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(pos[i]){//ATK
                    if(strength[1][j] >= strength[0][i]){
                        km2.add(i, j, strength[1][j] - strength[0][i]);
                    }else{
                        km2.add(i, j, -1000000);
                    }
                }else{
                    if(strength[1][j] > strength[0][i]){
                        km2.add(i, j, 0);
                    }else{
                        km2.add(i, j, -1000000);
                    }
                }
            }
        }
        for(int i=0;i<M;i++){
            for(int j=N;j<M;j++){
                km2.add(j, i, strength[1][i]);
            }
        }
        ans = max(ans, km2.Solve());
    }
    printf("%d\n", ans);
    return 0;
}
