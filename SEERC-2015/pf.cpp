#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-15
#define INF 1e15
struct Function {
	vector<double> coef;
	Function(const vector<double> &c=vector<double>()): coef(c){}
	double operator () (const double &rhs) const {
		double res = 0.0;
		double e = 1.0;
		for(int i=0;i<(int)coef.size();i++,e*=rhs)
			res += e * coef[i];
		return res;
	}
	Function derivative() const {
		vector<double> dc(coef.size()-1);
		for(int i=0;i<(int)dc.size();i++)
			dc[i] = coef[i + 1] * (i + 1);
		return Function(dc);
	}
	int degree() const {
		return coef.size() - 1;
	}
};
int sign(double x){
	return x < -EPS ? -1 : x > EPS;
}
/* called by equation */
template<class T>
double find(const T &f, double lo, double hi){
	int sign_lo, sign_hi;
	if((sign_lo = sign(f(lo))) == 0) return lo;
	if((sign_hi = sign(f(hi))) == 0) return hi;
	if(sign_hi * sign_lo > 0) return INF;
	while(hi - lo > EPS){
		double m = (hi + lo) / 2;
		int sign_mid = sign(f(m));
		if(sign_mid == 0) return m;
		if(sign_lo * sign_mid < 0)
			hi = m;
		else lo = m;
	}
	return (lo + hi) / 2;
}
/*
 * return a set of answer of f(x) = 0
 */
template<class T>
vector<double> equation(const T &f){
	vector<double> res;
	if(f.degree() == 1){
		if(sign(f.coef[1]))res.push_back(-f.coef[0] / f.coef[1]);
		return res;
	}
	vector<double> droot = equation(f.derivative());
	droot.insert(droot.begin(), -INF);
	droot.push_back(INF);
	for(int i=0;i<(int)droot.size()-1;i++){
		double tmp = find(f, droot[i], droot[i + 1]);
		if(tmp < INF) res.push_back(tmp);
	}
	return res;
}

typedef long long ll;
vector<ll> func(const vector<ll> &x, int d){
    int n = x.size();
    vector<ll> res(x.size());
    res[n - 1] = x[n - 1];
    for(int i=n-2;i>=0;i--){
        res[i] = res[i + 1] * d + x[i];
    }
    return res;
}

int main(){
    int N;
    scanf("%d", &N);
    vector<ll> c(N + 1);
    c[N] = 1;
    for(int i=N-1;i>=0;i--)
        scanf("%I64d", &c[i]);
    int cnt = 0;
    for(int i=-10;i<=10;i++){
        while(true){
            auto x = func(c, i);
            if(x[0] != 0){
                break;
            }
            for(int j=0;j<(int)x.size()-1;j++){
                c[j] = x[j+1];
            }
            c.pop_back();
            cnt++;
        }
    }
    printf("%d\n", N - cnt);
    return 0;
}
