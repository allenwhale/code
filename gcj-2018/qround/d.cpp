#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

struct Point {
    double x, y, z;
    Point(double _x=0, double _y=0, double _z=0): x(_y), y(_x), z(_z) {}
    Point ry(double t){
        return { 
            x * cos(t) + z * sin(t), 
            y, 
            -x * sin(t) + z * cos(t)
        };
    }
    Point rz(double t){
        return {
            x * cos(t) - y * sin(t),
            x * sin(t) + y * cos(t),
            z
        };
    }
    void print() const {
        printf("%.12g %.12g %.12g\n", x, y, z);
    }
};

void Solve(){
    double A;
    scanf("%lf", &A);
    if(A <= sqrt(2.)){
        double t = PI / 4. - asin(A / sqrt(2.));
        Point(.5, 0, 0).ry(t).print();
        Point(0, .5, 0).ry(t).print();
        Point(0, 0, .5).ry(t).print();
    }else{
        double t = asin(A / -sqrt(3)) + atan(sqrt(2));
        Point(.5, 0, 0).ry(PI / 4).rz(t).print();
        Point(0, .5, 0).ry(PI / 4).rz(t).print();
        Point(0, 0, .5).ry(PI / 4).rz(t).print();
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1 ; i <= T ; i++){
        printf("Case #%d:\n", i);
        Solve();
    }
    return 0;
}
