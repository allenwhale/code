#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define EPS 1e-9
typedef long long ll;
template<class T> class Matrix{ public:
    vector<vector<T> > D;
    int R, C;
    Matrix(int r=0, int c=0): R(r), C(c) {
        D = vector<vector<T> >(R, vector<T>(C));
    }

    Matrix(const Matrix &rhs): D(rhs.D), R(rhs.R), C(rhs.C) {}

    Matrix& operator = (const Matrix &rhs) {
        R = rhs.R;
        C = rhs.C;
        D = rhs.D;
    }

    T& at(const int &x, const int &y) {
        return D[x][y];
    }

    const T& at(const int &x, const int &y) const {
        return D[x][y];
    }

    Matrix operator + (const Matrix &rhs) const {
        if(R != rhs.R || C != rhs.C) return Matrix();
        Matrix res(R, C);
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                res.at(i, j) = at(i, j) + rhs.at(i, j);
        return res;
    }

    Matrix operator - (const Matrix &rhs) const {
        if(R != rhs.R || C != rhs.C) return Matrix();
        Matrix res(R, C);
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                res.at(i, j) = at(i, j) - rhs.at(i, j);
        return res;
    }

    Matrix operator * (const Matrix &rhs) const {
        if(C != rhs.R) return Matrix();
        Matrix res(R, rhs.C);
        for(int i=0;i<R;i++)
            for(int j=0;j<rhs.C;j++)
                for(int k=0;k<C;k++)
                    res.at(i, j) += at(i, k) * rhs.at(k ,j);
        return res;
    }

    /* make itself an identity matrix */
    void Identity() {
        for(int i=0;i<R;i++)
            at(i, i) = 1;
    } 

    // A^rhs
    Matrix pow(int rhs) const {
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

    /*
     * return guass eliminated matrix 
     * r will be changed to the number of the non-free variables
     * l[i] will be set to true if i-th variable is not free
     * ignore the last flag columns
     */
    Matrix GuassElimination(int &r, vector<bool> &l, int flag=0) {
        l = vector<bool>(C);
        r = 0;
        Matrix res(*this);
        for(int i=0;i<res.C-flag;i++){
            for(int j=r;j<res.R;j++){
                if(fabs(res.at(j, i)) > EPS){
                    swap(res.D[r], res.D[j]);
                    break;
                }
            }
            if(fabs(res.at(r, i)) < EPS){
                continue;
            }
            for(int j=0;j<res.R;j++){
                if(j != r && fabs(res.at(j, i)) > EPS){
                    double tmp = (double)res.at(j, i) / (double)res.at(r, i);
                    for(int k=0;k<res.C;k++){
                        res.at(j, k) -= tmp * res.at(r, k);
                    }
                }
            }
            r++;
            l[i] = true;
        }
        return res;
    }

    /*
     * Ax = b
     * it will return the answer(x)
     * if row != column or there is any free variable, it will return an empty vector
     */
    vector<double> Solve(const vector<double> &a) {
        if(R != C) return vector<double>();
        vector<double> res(R);
        Matrix t(R, C+1);
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)
                t.at(i, j) = at(i, j);
            t.at(i, C) = a[i];
        }
        int r = 0;
        vector<bool> l;
        t = t.GuassElimination(r, l, 1);
        if(r != R) return vector<double>();
        for(int i=0;i<C;i++){
            if(l[i])for(int j=0;j<R;j++){
                if(fabs(t.at(j, i)) > EPS)
                    res[i] = t.at(j, C) / t.at(j, i);
            }
        }
        return res;
    }

    /*
     * return an inverse matrix
     * if row != column or the inverse matrix doesn't exist, it will return an empty matrix
     */
    Matrix Inverse() {
        if(R != C) return Matrix();
        Matrix t(R, R * 2);
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)
                t.at(i, j) = at(i, j);
            t.at(i, i + R) = 1;
        }
        int r = 0;
        vector<bool> l;
        t = t.GuassElimination(r, l, R);
        if(r != R)return Matrix();
        for(int i=0;i<C;i++){
            for(int j=0;j<R;j++){
                if(fabs(t.at(j, i)) > EPS){
                    for(int k=0;k<C;k++)
                        t.at(j, C + k) /= t.at(j, i);
                }
            }
        }
        Matrix res(R, C);
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                res.at(i, j) = t.at(i, j + C);
        return res;
    }

    friend ostream& operator << (ostream &out, const Matrix<T> &rhs) {
        for(int i=0;i<rhs.R;i++)
            for(int j=0;j<rhs.C;j++)
                out << rhs.at(i, j) << (j == rhs.C - 1 ? '\n' : ' ');
        return out;
    }
};

int main(){
    int N, M, S, T;
    scanf("%d%d%d%d", &N, &M, &S, &T);
    Matrix<ll> m(N, N);
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        m.at(a, b) = m.at(b, a) = 1;
    }
    m = m.pow(T);
    ll ans = 0;
    for(int i=0;i<N;i++)
        ans += m.at(i, S);
    printf("%lld\n", ans);
}
