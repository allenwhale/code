#include <bits/stdc++.h>
using namespace std;
int F[1010];
vector<int> vc[1010];
bool couple[1010];
int vis[1010];
int circle[1010];
int longest[1010];
stack<int> st;
void count_circle(int x, int c){
    //printf("  %d %d %d\n", x, F[x], c);
    st.push(x);
    vis[x] = c;
    if(vis[F[x]]){
        int cir = c - vis[F[x]] + 1;
        while(st.top() != F[x]){
            circle[st.top()] = cir;
            st.pop();
        }
        //printf("col %d %d\n", x, F[x]);
        circle[F[x]] = cir;
        st.pop();
        while(st.size()){
            circle[st.top()] = -1;
            st.pop();
        }
    }else{
        count_circle(F[x], c + 1);
    }
}
int count_longest(int x){
    //printf("%d\n", x);
    if(longest[x] != -1)return longest[x];
    int res = 1;
    for(int i=0;i<(int)vc[x].size();i++){
        if(couple[vc[x][i]] == false)
            res = max(res, count_longest(vc[x][i]) + 1);
    }
    return longest[x] = res;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int N;
        scanf("%d", &N);
        for(int i=1;i<=N;i++)
            vc[i].clear();
        for(int i=1;i<=N;i++){
            scanf("%d", &F[i]);
            vc[F[i]].push_back(i);
        }
        int cnt_couple = 0;
        memset(circle, 0, sizeof(circle));
        memset(couple, false, sizeof(couple));
        memset(longest, -1, sizeof(longest));
        for(int i=1;i<=N;i++){
            if(F[F[i]] == i){
                cnt_couple++;
                couple[i] = couple[F[i]] = true;
            }
        }
        //printf("couple %d\n", cnt_couple);
        for(int i=1;i<=N;i++){
            if(couple[i] == false && circle[i] == 0){
                memset(vis, 0, sizeof(vis));
                count_circle(i, 1);
            }
        }
        int ans = 0, tmp = 0;
        for(int i=1;i<=N;i++)
            ans = max(ans, circle[i]);
        for(int i=1;i<=N;i++){
            if(couple[i]){
                //printf("%d\n", i);
                longest[i] = count_longest(i);
                //printf("long %d %d\n", i, longest[i]);
                tmp += longest[i] - 1;
            }
        }
        //printf("tmp %d \n", tmp);
        ans = max(ans, tmp + cnt_couple);

        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
