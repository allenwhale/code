#include <bits/stdc++.h>
using namespace std;
int ss[200010], p[200010];
map<int,int>mp;
int main(){
    int N, Q;
    scanf("%d%d",&N,&Q);
    for(int i=0;i<N;i++)
        scanf("%d",&ss[i]), p[i]=ss[i],mp[ss[i]]=i;
    sort(p,p+N);
    while(Q--){
        int a, l, flag=1;
        scanf("%d%d",&a,&l);
        int s=lower_bound(p,p+N,ss[a-1])-p;
        int f=0;
        int ls=-1;
        while(1){
            int ns;
            if(flag)
                ns=upper_bound(p+s,p+N, p[s]+l)-p-1;
            else
                ns=lower_bound(p,p+s,p[s]-l)-p;
            flag ^= 1;
            int ll=abs(p[s]-p[ns]);
            l-=ll;
            if(ns==s&&f++)
                break;
            if(ns==ls)
                l %= (2*ll);
            ls=s;
            s=ns;
        }

        printf("%d\n",mp[p[s]]+1);
    }
    return 0;
}
