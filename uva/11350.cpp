#include <bits/stdc++.h>
using namespace std;
struct Var{
    long long a, b;
    Var(long long _a, long long _b):a(_a), b(_b){}
    Var& update(){
        if(!a||!b)return *this;
        long long d = __gcd(a,b);
        a/=d;b/=d;
        return *this;
    }
    Var operator + (const Var &rhs) const{
        return Var(a+rhs.a,b+rhs.b);
    }
};
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        char s[100];
        scanf("%s",s);
        Var l(0,1),m(1,1),r(1,0);
        for(int i=0;s[i];i++){
            if(s[i]=='R'){
                l=m;
                m=m+r;
            }else if(s[i]=='L'){
                r=m;
                m=m+l;
            }
        }
        m.update();
        printf("%lld/%lld\n",m.a,m.b);
    }
}

