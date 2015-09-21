#include <bits/stdc++.h>
using namespace std;
int main(){
    double a,b;
    scanf("%lf %lf",&a,&b);
    if(b>a){
        puts("-1");
        return 0;
    }
    if(fabs(a-b)<=1e-12){
        printf("%.12f\n",a);
        return 0;
    }
    double tmp=b;
    a/=b;
    b=1;
    double d1=(a+b)/2,d2=(a-b)/2;
    d1/=double(floor(d1));
    d2/=double(floor(d2));
    printf("%.12f\n",min(d1,d2)*tmp);
    return 0;
}
