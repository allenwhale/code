#include <bits/stdc++.h>
using namespace std;
#define f first 
#define s second
typedef pair<int, int> PI;
//typedef 
void Solve(){
    int M;
    scanf("%d",&M);
    int l,r;
    vector<PI> s;
    while(~scanf("%d%d",&l,&r)&&(l||r)){
        s.push_back({l,r});
    }
    sort(s.begin(),s.end());
    priority_queue<PI> pq;
    vector<PI> ans;
    int now=0, last=0;
    while(now<M){
        while(last<(int)s.size()&&s[last].f<=now){
            pq.push({s[last].s,s[last].f});
            last++;
        }
        if(pq.empty())
            break;
        PI tmp=pq.top();
        pq.pop();
        now=tmp.f;
        ans.push_back(tmp);
    }
    if(now<M)printf("0\n");
    else{
        printf("%d\n", (int)ans.size());
        for(PI seg: ans)
            printf("%d %d\n", seg.s, seg.f);
    }

}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        Solve();
        if(T)puts("");
    }
    return 0;
}
