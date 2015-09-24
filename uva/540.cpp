#include <bits/stdc++.h>
using namespace std;
int T;
map<int,int>mp;
bool in[1010];
void Solve(){
    memset(in,false,sizeof(in));
    queue<int>ao;
    queue<int>to[1010];
    char cmd[100];
    while(~scanf("%s",cmd)&&strcmp(cmd, "STOP")){
        if(strcmp(cmd,"ENQUEUE") == 0){
            int x;
            scanf("%d",&x);
            int t=mp[x];
            if(!in[t]){
                in[t]=true;
                ao.push(t);
            }
            to[t].push(x);
        }else if(strcmp(cmd, "DEQUEUE") == 0){
            int t=ao.front();
            printf("%d\n", to[t].front());
            to[t].pop();
            if(to[t].size()==0){
                in[t]=false;
                ao.pop();
            }
        }
    }
}
int main(){
    int c=1;
    while(~scanf("%d",&T)&&T){
        mp.clear();
        for(int i=0;i<T;i++){
            int n;
            scanf("%d",&n);
            while(n--){
                int m;
                scanf("%d",&m);
                mp[m]=i;
            }
        }
        printf("Scenario #%d\n", c++);
        Solve();
        puts("");
    }
    return 0;
}
