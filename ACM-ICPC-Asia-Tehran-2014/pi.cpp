#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> PD;
#define f first
#define s second
PD p[100010];
bool Solve(int N){
    for(int i=0;i<N;i++){
        scanf("%lf%lf", &p[i].f, &p[i].s);
    }
    vector<double> args;
    for(int i=0;i<N-1;i++){
        args.push_back(atan2(p[i+1].s-p[i].s, p[i+1].f-p[i].f));
    }
    for(int k=0;k<4;k++){
        sort(args.begin(), args.end());
        bool fair = true;
        for(double arg: args){
            if(abs(arg-args[0]) > M_PI/2.0){
                fair = false;
            }
        }
        if(fair == true)return true;
        for(double &arg: args){
            arg += M_PI / 2.0;
        }
    }
    return false;

}
int main(){
    int N;
    while(~scanf("%d", &N)&&N){
        printf("%s\n", Solve(N)?"Fair":"Unfair");
    }
    return 0;
}
