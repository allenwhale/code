#include <bits/stdc++.h>
using namespace std;
typedef complex<double> CD;
CD n[110];
double len[110],s[110];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            double a,b;
            scanf("%lf %lf",&a,&b);
            n[i]=CD(a,b);
        }
        double all=0.0;
        for(int i=1;i<N;i++)
            all+=s[i-1]=abs(n[i]-n[i-1]);
        for(int i=0;i<N;i++)
            s[i]/=all;
        int t;
        double per;
        scanf("%d %lf",&t,&per);
        while(--t){
            int i=0;
            while(per>s[i])per-=s[i++];
            per/=s[i];
            CD O=n[i]-n[0];
            CD n0=n[0];
            double arg1=arg(n[i]-n[i+1]),arg2=arg(n[0]-n[N-1]);
            double M=abs(n[i+1]-n[i])/abs(n[N-1]-n[0]);
            CD turn(cos(arg1-arg2),sin(arg1-arg2));
            for(int i=0;i<N;i++){
                n[i]-=n0;
                n[i]*=turn;
                n[i]*=M;
                n[i]+=n0;
                n[i]+=O;
            }
        }
        int i=0;
        while(per>s[i])per-=s[i++];
        per/=s[i];
        CD ans=(per*n[i+1]+(1.0-per)*n[i]);
        printf("(%f,%f)\n",ans.real(),ans.imag());
    }
    return 0;
}
