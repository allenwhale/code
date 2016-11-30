#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector<int> vc;
bool check(){
    vector<int> tmp;
    tmp.push_back(INT_MIN);
    for(int i : vc){
        if(i > tmp.back())tmp.push_back(i);
        *lower_bound(tmp.begin(), tmp.end(), i) = i;
    }
    return (int)tmp.size() == K + 1;
}
int ans = 0;
void dp(int x){
    if(x == N){
        if(check()){
            for(int i : vc){
                printf("%d ", i);
            }
            puts("");
        ans++;
        }
        return;
    }
    for(int i=1;i<=M;i++){
        vc.push_back(i);
        dp(x + 1);
        vc.pop_back();
    }
}
int main(){
    while(1){
        scanf("%d%d%d", &N, &M, &K);
        ans = 0;
        dp(0);
        printf("%d\n", ans);
    }
    return 0;
}
