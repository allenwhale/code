#include <bits/stdc++.h>
using namespace std;
double D;
int N,B;
double p[20],h[20];
#define sqr(x) ((x)*(x))
#define g 1.0
double calc(double d,double np,double nh){
    if(fabs(np)<=1e-6)return 1e9;
    double a=nh/(sqr(np-d/2)-sqr(d/2));
    double b=-a*sqr(d/2);
    //printf("p=%f h=%f\n",np,nh);
    //printf("y=%f*(x-%f)^2+%f\n", a,d/2,b);
    double vx2=-0.5/a;
    double vy2=a*a*d*d*vx2;
    //printf("%f %f\n", sqrt(vx2), sqrt(vy2));
    if(vy2<vx2){
        return sqrt(d);
    }
    return sqrt(vx2+vy2);
}
int main(){
    scanf("%lf%d%d",&D,&N,&B);
    for(int i=0;i<N;i++){
        scanf("%lf%lf",&p[i],&h[i]);
    }
    double ans=1e9;
    for(int i=1;i<=B+1;i++){
        double d=D/(double)i;
        double v=0;
        for(int j=0;j<N;j++){
            double new_p=p[j]-d*(double)floor(p[j]/d);
            v=max(v,calc(d,new_p,h[j]));
        }
        ans=min(ans,v);
    }
    printf("%f\n", ans);
}
