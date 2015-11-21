#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int mp[110][110];
int h[110][110];
int l[110][110];
int r[110][110];
typedef pair<int,int> PI;
int Solve(){
    int N,M;
    scanf("%d%d",&N,&M);
    if(N==0&&M==0)return -1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    memset(h,0,sizeof(h));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            h[i][j]=(mp[i][j]==0)?h[i-1][j]+1:0;
        }
    }
    for(int i=1;i<=N;i++){
        stack<PI>st;
        st.push({-10000000, 0});
        for(int j=1;j<=M;j++){
            while(st.size()&&st.top().f>=h[i][j])
                st.pop();
            l[i][j]=st.top().s+1;
            st.push({h[i][j],j});
        }
    }
    for(int i=1;i<=N;i++){
        stack<PI>st;
        st.push({-10000000, N+1});
        for(int j=M;j>=1;j--){
            while(st.size()&&st.top().f>=h[i][j])
                st.pop();
            r[i][j]=st.top().s-1;
            st.push({h[i][j],j});
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            ans=max(ans, h[i][j]*(r[i][j]-l[i][j]+1));
        }
    }
    return ans;
}
int main(){
    int ans;
    while((ans=Solve()) != -1){
        printf("%d\n", ans);
    }
}
