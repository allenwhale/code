#include <bits/stdc++.h>
using namespace std;
int p[510];
int fp[510];
int w[510]={0};
int cnt[510];
typedef pair<int,int> PI;
vector<PI> vc[510];
PI dp[510];
map<int,int>mp;
int sn=0;
int find(int x){
    if(mp.find(x)==mp.end())
        mp[x]=sn++;
    return mp[x];
}
int dfs(int x, int p){
    find(x);
    for(auto v:vc[x]){
        if(p!=v.first){
            dfs(v.first,x);
        }
    }
}
int N, L;
PI DFS(int x){
    if(x==N)return PI(0,0);
    if(dp[x]!=PI(-1,-1))return dp[x];
    dp[x]=PI(-1,100000000);
    int cnt=0;
    int i;
    for(i=x;i<N;i++){
        cnt+=fp[i];
        if(cnt>=L)break;
    }
    for(i++;cnt>=L&&i<=N;i++){
        PI tmp=DFS(i);
        tmp.first+=1;
        tmp.second+=w[i-1];
        if(tmp.first>dp[x].first)
            dp[x]=tmp;
        if(tmp.first==dp[x].first&&tmp.second<dp[x].second)
            dp[x]=tmp;
    }
    return dp[x];
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(cnt,0,sizeof(cnt));
        mp.clear();
        sn=0;
        scanf("%d %d",&N,&L);
        fill(dp,dp+N,PI(-1,-1));
        for(int i=0;i<N;i++)
            vc[i].clear();
        for(int i=0;i<N;i++)
            scanf("%d",&p[i]);
        for(int i=0;i<N-1;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            a--,b--;
            cnt[a]++,cnt[b]++;
            vc[a].push_back(PI(b,c));
            vc[b].push_back(PI(a,c));
        }
        int root=0;
        for(int i=0;i<N;i++){
            if(cnt[i]==1)root=i;
        }
        dfs(root,-1);
        for(int i=0;i<N;i++)
            fp[find(i)]=p[i];
        for(int i=0;i<N;i++){
            for(auto v:vc[i]){
                if(find(i)<find(v.first))
                    w[find(i)]=v.second;
            }
        }
        w[N-1]=0;
        PI ans=DFS(0);
        if(ans.first != -1)
            printf("%d %d\n", ans.first, ans.second);
        else puts("-1");
    }
    return 0;
}
