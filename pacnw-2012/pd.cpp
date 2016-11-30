#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define EPS 1e-6 
const double PI = acos(-1);
int cmp(double x){
	if(fabs(x) < EPS) return 0;
	if(x > 0) return 1;
	else return -1;
}
struct Point{
    double x, y;
	double Arg() const {
		double res = atan2(y, x);
		if(cmp(res) < 0) res += PI * 2.0;
		return res;
	}
    bool operator < (const Point &n) const {
        return Arg() < n.Arg();
    }
}p[50010];
int N;
double W, H;
double deg[100010];
void Solve(){
    for(int i=0;i<N;i++){
        scanf("%lf%lf", &p[i].x, &p[i].y);
        p[i].x -= W / 2;
        p[i].y -= H / 2;
    }
    sort(p, p + N);
    //for(int i=0;i<N;i++){
        //printf("p %f %f\n", p[i].x, p[i].y);
    //}
    for(int i=0;i<N;i++){
        deg[i] = p[i].Arg();
        deg[i + N] = p[i].Arg() + 2 * PI;
    }
    deg[2 * N] = p[0].Arg() + 4 * PI;
    for(int i=0;i<N;i++){
        int a1 = i, b1 = i + 1;
        int a2 = i + N / 2, b2 = i + 1 + N / 2;
        double l1 = deg[a1] + PI, r1 = deg[b1] + PI;
        double l2 = deg[a2], r2 = deg[b2];
        if(max(r1, r2) - min(l1, l2) <= (r1 - l1) + (r2 - l2)){
            for(int j=b1;j<=a2;j++){
                printf("%d %d\n", int(p[j % N].x + W / 2 + 0.1), int(p[j % N].y + H / 2 + 0.1));
            }
            return;
        }
    }
}
int main(){
    while(~scanf("%d%lf%lf", &N, &W, &H)){
        if(N == 0 && W == 0 && H == 0)break;
        Solve();
    }
    return 0;
}
