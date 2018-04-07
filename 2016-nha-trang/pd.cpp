#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, M;
vector<int> build(char *T) {
    int lenT = strlen(T);
    vector<int> fail(lenT);
    for(int i=1, j=fail[0]=-1;i<lenT;i++) {
        while(j >= 0 && T[j + 1] != T[i])
            j = fail[j];
        if(T[j + 1] == T[i]) j++;
        fail[i] = j;
    }
    return fail;
}
class Matrix{ public:
    //array<array<__int128, 51>, 51> D;
    vector<vector<__int128>> D;
	int R, C;
	Matrix(int r=0, int c=0): R(r), C(c) {
		D = vector<vector<__int128> >(R, vector<__int128>(C));
	}

	Matrix(const Matrix &rhs): D(rhs.D), R(rhs.R), C(rhs.C) {}

	Matrix& operator = (const Matrix &rhs) {
		R = rhs.R;
		C = rhs.C;
		D = rhs.D;
        return *this;
	}

	__int128& at(const int &x, const int &y) {
		return D[x][y];
	}

	const __int128& at(const int &x, const int &y) const {
		return D[x][y];
	}

	/* make itself an identity matrix */
	void Identity() {
		for(int i=0;i<R;i++)
			at(i, i) = 1;
	} 

	Matrix operator * (const Matrix &rhs) const {
		Matrix res(R, rhs.C);
		for(int i=0;i<R;i++)
			for(int j=0;j<rhs.C;j++)
				for(int k=0;k<C;k++){
					res.at(i, j) += (at(i, k) * rhs.at(k ,j)) % (__int128)M;
                    if(res.at(i, j) >= M)
                        res.at(i, j) -= M;
                }
		return res;
	}

	// A^rhs
	Matrix pow(ll rhs) const {
		if(R != C) return Matrix();
		Matrix res(R, R), p(*this);
		res.Identity();
		while(rhs){
			if(rhs & 1)res = res * p;
			p = p * p;
			rhs >>= 1;
		}
		return res;
	}


	friend ostream& operator << (ostream &out, const Matrix &rhs) {
		for(int i=0;i<rhs.R;i++)
			for(int j=0;j<rhs.C;j++)
				out << (ll)rhs.at(i, j) << (j == rhs.C - 1 ? '\n' : ' ');
		return out;
	}
};

void Solve(){
    char s[100];
    scanf("%lld%lld", &n, &M);
    scanf("%s", s);
    auto fail = build(s);
    int len = strlen(s);
    Matrix mat(len + 1, len + 1);
    for(int i = 0 ; s[i] ; i++){
        for(int k = 'a' ; k <= 'z' ; k++){
            int j = i - 1;
            while(j >= 0 && s[j + 1] != k)
                j = fail[j];
            if(s[j + 1] == k)j++;
            mat.at(i, j + 1)++;
        }
    }
    mat.at(len, len) = 26;
    //cout << mat << endl;
    mat = mat.pow(n);
    //cout << mat << endl;
    printf("%lld\n", (ll)mat.at(0, len));
}
int main(){
    Matrix m(50, 50);
    int T;
    scanf("%d", &T);
    while(T--){
        Solve();
    }
    return 0;
}
