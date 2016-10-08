#include <bits/stdc++.h>
using namespace std;
bool active[100010];
int law[100010];
char in[100];
int main(){
    freopen("bureau.in", "r", stdin);
    freopen("bureau.out", "w", stdout);
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        active[i] = true;
        scanf("%s", in);
        if(in[0] == 'd'){
            law[i] = 0;
        }else{
            scanf("%d", &law[i]);
        }
    }
    for(int i=N;i>0;i--){
        if(active[i] && law[i]){
            active[law[i]] = false;
        }
    }
    int cnt = 0;
    vector<int> ans;
    for(int i=1;i<=N;i++){
        cnt += active[i];
        if(active[i])
            ans.push_back(i);
    }
    printf("%d\n", cnt);
    for(int i=0;i<(int)ans.size();i++){
        printf("%d", ans[i]);
        if(i == (int)ans.size() - 1)
            printf("\n");
        else printf(" ");
    }
            
    return 0;
}
