#include <bits/stdc++.h>
using namespace std;
struct KM{
#define FF first
#define SS second
#define INF 0x3f3f3f3f
	typedef pair<int, int> PI;
	int Nx, Ny;
	vector<vector<int> >mp;
	vector<int> visx, visy;
	vector<int> lx, ly, slack;
	vector<int> mx, my;
	KM(int x=0, int y=0): Nx(x), Ny(y), mp(vector<vector<int> >(Nx+1, vector<int>(Ny+1, 0))) {}
	void add(int x, int y, int w){
		mp[x][y] = w;
	}

	bool Match(int x){
		visx[x] = 1;
		for(int i=0;i<Ny;i++){
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
		mx = vector<int>(Nx+1, -1);
		my = vector<int>(Ny+1, -1);
		lx = vector<int>(Nx+1, -INF);
		ly = vector<int>(Ny+1, 0);
		slack = vector<int>(Ny+1, INF);
		visx = vector<int>(Nx+1, 0);
		visy = vector<int>(Ny+1, 0);
		for(int i=0;i<Nx;i++)
			for(int j=0;j<Ny;j++)
				lx[i] = max(lx[i], mp[i][j]);
		for(int i=0;i<Nx;i++){
			fill(slack.begin(), slack.end(), INF);
			while(true){
				fill(visx.begin(), visx.end(), 0);
				fill(visy.begin(), visy.end(), 0);
				if(Match(i)) break;
				int d = INF;
				for(int j=0;j<Ny;j++)
					if(!visy[j]) d = min(d, slack[j]);
				if(d == INF)break;
				for(int i=0;i<Nx;i++)
					if(visx[i]) lx[i] -= d;
				for(int i=0;i<Ny;i++)
					if(visy[i]) ly[i] += d;
					else slack[i] -= d;
			}
		}
		int res = 0;
		for(int i=0;i<Nx;i++)
			if(mx[i] != -1)
				res += mp[i][mx[i]];
		return res;
	}
};
int N, M;
int mp[510][510];
int c[510], d[510];
void Solve(){
    memset(mp, 0x3f, sizeof(mp));
    scanf("%d%d", &N, &M);
    for(int i=0;i<N;i++)
        mp[i][i] = 0;
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        mp[a][b] = mp[b][a] = 1;
    }
    for(int i=0;i<N;i++)
        scanf("%d", &c[i]);
    for(int i=0;i<N;i++)
        scanf("%d", &d[i]);
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
    vector<int> b2w, w2b;
    for(int i=0;i<N;i++){
        if(c[i] == 0 && d[i] == 1)
            w2b.push_back(i);
        else if(c[i] == 1 && d[i] == 0)
            b2w.push_back(i);
    }
    KM km(w2b.size(), b2w.size());
    for(int i=0;i<(int)w2b.size();i++){
        for(int j=0;j<(int)b2w.size();j++){
            km.add(i, j, mp[w2b[i]][b2w[j]]);
        }
    }
    printf("%d\n", km.Solve());
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
