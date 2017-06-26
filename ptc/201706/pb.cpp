#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M;
        scanf("%d%d", &N, &M);
        vector<int> a, b;
        for(int i = 0 ; i < N ; i++){
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        for(int i = 0 ; i < M ; i++){
            int x;
            scanf("%d", &x);
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans = 0;
        int now = 0;
        for(int i = 0 ; i < N ; i++){
            ans += now + a[i] / 2;
            now += a[i];
        }
        now = 0;
        for(int i = 0 ; i < M ; i++){
            ans += now + b[i] / 2;
            now += b[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
