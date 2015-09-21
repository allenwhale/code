#include <bits/stdc++.h>
using namespace std;
double a[200010];
int N;
double check(double x){
    double ans=0,tmp=0;
    for(int i=0;i<N;i++){
        if(tmp<0)tmp=0;
        tmp+=(a[i]-x);
        ans=max(ans,fabs(tmp));
    }
    tmp=0;
    for(int i=0;i<N;i++){
        if(tmp>0)tmp=0;
        tmp+=(a[i]-x);
        ans=max(ans,fabs(tmp));
    }
    return ans;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lf",&a[i]);
    }
    double l=-1e4,r=1e4;
    while(fabs(l-r)>1e-12){
        double d=(r-l)/3;
        double m1=l+d,m2=r-d;
        double c1=check(m1),c2=check(m2);
        //printf("%f %f %f %f %f %f\n",l,r,m1,c1,m2,c2);
        if(c1>c2)l=m1;
        else r=m2;
    }
    printf("%.9f\n",check((l+r)/2));
    return 0;
}
