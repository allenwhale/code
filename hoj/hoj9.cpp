#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
struct P{
    int v;
    double c;
}out;
vector<P> s[2005];
queue<int> que;
double d[2005];
int in[2005]={0},r[2005]={0};
int main(){
    int n,m,i,j,p,st,ed,x,y;
    double v,val;
    scanf("%d%d%lf%d%d",&n,&m,&v,&st,&ed);
    for(i=0;i<m;i++){
        scanf("%d%d%lf",&x,&y,&val);
        s[x].push_back((P){y,val});
    }
    for(i=1;i<=n;i++)
        d[i]=999999999999999.0;
    d[st]=1,in[st]=1;
    que.push(st);
    while(que.size()){
        x=que.front();
        que.pop();
        in[x]=0,r[x]++;
        if(r[x]>2*n){
            puts("0");
            return 0;
        }
        for(i=0;i<s[x].size();i++){
            out=s[x][i];
            if(d[x]*out.c<d[out.v]){
                d[out.v]=d[x]*out.c;
                if(in[out.v]==0){
                    in[out.v]=1;
                    que.push(out.v);
                }
            }
        }
    }
    printf("%.lf\n",v*d[ed]);
}
