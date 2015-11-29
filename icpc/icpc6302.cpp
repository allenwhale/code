#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
#define f first
#define s second
int N;
vector<PI> vc[5010];
char name[5010];
bool car[256];
int dis[5010];
PI pre[5010];
const int INF=0x3f3f3f3f;
void Solve(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        vc[i].clear();
    for(int i=0;i<N;i++){
        int id;
        scanf("%d",&id);
        char n[3];
        scanf("%s",n);
        name[id]=n[0];
        int s;
        scanf("%d",&s);
        for(int j=0;j<s;j++){
            char t[20];
            int to;
            scanf("%s %d",t,&to);
            vc[id].push_back({stoi(t+1),to});
        }
    }
    int Q;
    scanf("%d",&Q);
    while(Q--){
        memset(car,false,sizeof(car));
        memset(dis,0x3f,sizeof(dis));
        int s,e;
        char cars[30];
        scanf("%d %d %s",&s,&e,cars);
        int len=strlen(cars);
        for(int i=0;i<len;i++)
            car[(int)cars[i]]=true;
        queue<int> q;
        q.push(s);
        dis[s]=0;
        while(!q.empty()){
            int now=q.front();
            //printf("now %d\n", now);
            q.pop();
            for(int i=0;i<(int)vc[now].size();i++){
                PI e=vc[now][i];
                if(dis[e.s]>dis[now]+!(car[(int)name[now]]&&car[(int)name[e.s]])){
                    //printf("go %d\n", e.s);
                    dis[e.s]=dis[now]+!(car[(int)name[now]]&&car[(int)name[e.s]]);
                    pre[e.s]={e.f,now};
                    q.push(e.s);
                }else if(dis[e.s]==dis[now]+!(car[(int)name[now]]&&car[(int)name[e.s]])&&pre[e.s].f>e.f){
                    //printf("go %d\n", e.s);
                    pre[e.s]={e.f,now};
                }
            }
        }
        vector<int> ans;
        for(int t=e;t!=s;t=pre[t].s){
            //printf("%d %d\n", t, pre[t].s);
            if(!(car[(int)name[t]]&&car[(int)name[pre[t].s]]))
                ans.push_back(pre[t].f);
        }
        for(int i=(int)ans.size()-1;i>=0;i--){
            printf("T%d%c",ans[i],i?' ':'\n');
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        Solve();
    }
    return 0;
}
