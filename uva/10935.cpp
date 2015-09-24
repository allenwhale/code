#include <bits/stdc++.h>
using namespace std;
void Solve(int n){
    queue<int> q;
    for(int i=1;i<=n;i++)
        q.push(i);
    vector<int>vc;
    while(q.size()>1){
        vc.push_back(q.front());
        q.pop();
        q.push(q.front());
        q.pop();
    }
    printf("Discarded cards:");
    bool f=true;
    for(int v: vc){
        if(!f)printf(",");
        f=false;
        printf(" %d", v);
    }
    puts("");
    printf("Remaining card: %d\n", q.front());
}
int main(){
    int N;
    while(~scanf("%d",&N)&&N){
        Solve(N);
    }
    return 0;
}
