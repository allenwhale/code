#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
#define f first
#define s second
int N;
PI s[100010];
int c[300]={0},cc[330];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&s[i].f);
    int cost=0;
    for(int i=0;i<N;i++)
        scanf("%d",&s[i].s),cost+=s[i].s;
    sort(s,s+N);
    int pos=0;
    int ans=100000000;
    while(pos<N){
        int now=upper_bound(s+pos,s+N,PI(s[pos].f,500))-s;
        int ncost=cost;
        int num=pos-(now-pos)+1;
        for(int i=1;num>0;i++){
            int d=min(num,c[i]);
            num-=d;
            ncost+=d*i;
        }
        for(int i=pos;i<now;i++){
            c[s[i].s]++;
            ncost-=s[i].s;
            cost-=s[i].s;
        }
        pos=now;
        ans=min(ans,ncost);
    }
    printf("%d\n",ans);

    return 0;
}
