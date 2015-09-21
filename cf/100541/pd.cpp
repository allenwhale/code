#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll N, K;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&N,&K);
        if(K<=1000){
            long long tmp=N;
            for(int i=0;i<K;i++){
                tmp=(tmp+tmp%100);
            }
            printf("%lld\n",tmp);
            continue;
        }
        int n=N%100;
        set<int>s;
        vector<int>vc;
        ll sum=0;
        while(s.find(n)==s.end()){
            s.insert(n);
            vc.push_back(n);
            n=(n+n);
            if(n>=100){
                sum+=100;
                n%=100;
            }
        }
        int start=0;
        while(vc[start]!=n)start++;
        s.clear();vc.clear();
        sum=0;
        while(s.find(n)==s.end()){
            s.insert(n);
            vc.push_back(n);
            n=(n+n);
            if(n>=100){
                sum+=100;
                n%=100;
            }
        }
        n=N%100;
        ll sum2=0;
        for(int i=0;i<start;i++,K--){
            n=n+n;
            if(n>=100){
                sum2+=100;
                n%=100;
            }
        }
        int sz=vc.size();
        long long ans=sum*(K/(ll)sz);
        K%=sz;
        int carry=0;
        for(int i=0;i<K;i++){
            n+=n;
            if(n>=100){
                carry++;
                n%=100;
            }
        }
        printf("%lld\n",ans+N-N%100+vc[K]+carry*100+sum2);

    }
    return 0;
}
