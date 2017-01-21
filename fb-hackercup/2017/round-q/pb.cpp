#include <bits/stdc++.h>
using namespace std;

int Solve(){
    int N;
    scanf("%d", &N);
    vector<int> s(N);
    for(int i=0;i<N;i++){
        scanf("%d", &s[i]);
    }
    sort(s.begin(), s.end());
    int i = N - 1, j = 0, ans = 0;
    while(i >= j){
        int mx = s[i], cnt = 1;
        i--;
        while(mx * cnt < 50 && j <= i){
            mx = max(mx, s[j]);
            cnt++;
            j++;
        }
        if(mx * cnt >= 50){
            ans++;
        }
    }
    return ans;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: %d\n", t, Solve());
    }
    return 0;
}
