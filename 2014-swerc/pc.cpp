#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-2
typedef complex<double> Complex;
const double pi = acos(-1);
vector<Complex> reverse(const vector<Complex>& a){
	vector<Complex> res(a);
	for (int i=1,j=0;i<(int)res.size();i++){
		for(int k=((int)res.size())>>1;!((j^=k)&k);k>>=1);
		if(i > j) swap(res[i], res[j]);
	}
	return res;
}
vector<Complex> FFT(const vector<Complex>& a, int flag=1){
	vector<Complex> res = reverse(a);
	for(int k=2;k<=(int)res.size();k<<=1){
		double p0 = -pi / (k>>1) * flag;
		Complex unit_p0(cos(p0), sin(p0));
		for(int j=0;j<(int)res.size();j+=k){
			Complex unit(1.0, 0.0);
			for(int i=j;i<j+k/2;i++,unit*=unit_p0){
				Complex t1 = res[i], t2 = res[i+k/2] * unit;
				res[i] = t1 + t2;
				res[i+k/2] = t1 - t2;
			}
		}
	}
	if(flag == -1) for(auto &x:res) x /= (double)res.size();
	return res;
}
int main(){
    int N, M;
    scanf("%d", &N);
    vector<Complex> a(262144<<1);
    a[0] = Complex(1, 0);
    for(int i=0;i<N;i++){
        int x;
        scanf("%d", &x);
        a[x] = Complex(1, 0);
    }
    auto fft = FFT(a);
    for(auto &x : fft)
        x *= x;
    fft = FFT(fft, -1);
    for(int i=0;i<8;i++)
        printf("%d: %f\n", i, fft[i].real());
    int ans = 0;
    scanf("%d", &M);
    for(int i=0;i<M;i++){
        int x;
        scanf("%d", &x);
        if(fft[x].real() > EPS)
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}
