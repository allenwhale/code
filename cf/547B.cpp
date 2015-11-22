#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
#define f first
#define s second
vector<PI> a;
int p[200010];
int sz[200010];
bool vis[200010]={false};
int ans[200020]={0};
int find(int x){
    return x==p[x]?x:p[x]=find(p[x]);
}
void U(int a,int b){
    a=find(a);
    b=find(b);
    p[b]=a;
    sz[a]+=sz[b];
    sz[b]=0;
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        p[i]=i;
        sz[i]=1;
    }
    for(int i=0;i<N;i++){
        int tmp;
        scanf("%d",&tmp);
        a.push_back({tmp,i});
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i=0;i<(int)a.size();i++){
        vis[a[i].s]=true;
        if(a[i].s>0&&vis[a[i].s-1])U(a[i].s,a[i].s-1);
        if(a[i].s<N-1&&vis[a[i].s+1])U(a[i].s,a[i].s+1);
        for(int j=sz[find(a[i].s)];j>0&&ans[j]==0;j--)
            ans[j]=a[i].f;
    }
    for(int i=1;i<=N;i++)
        printf("%d%c",ans[i],i==N?'\n':' ');
    return 0;
}
