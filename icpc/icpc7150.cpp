#include <bits/stdc++.h>
using namespace std;
double s[1000010];
int main(){
    double p,a,b,c,d;
    int n;
    while(scanf("%lf%lf%lf%lf%lf%d",&p,&a,&b,&c,&d,&n)){
        s[0]=0;
        for(int i=1;i<=n;i++){
            s[i]=p*(sin(a*i+b)+cos(c*i+d)+2);
        }
        int h=0;
        double ans=0.0;
        for(int i=1;i<=n;i++){
            if(s[i]>s[h])h=i;
            else ans=max(ans, s[h]-s[i]);
        }
        printf("%.7f\n", ans);
    }
    return 0;
}
