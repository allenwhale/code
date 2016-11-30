#include <bits/stdc++.h>
using namespace std;
void Solve(){
    int N;
    scanf("%d", &N);
    vector<int> vc;
    for(int i=0;i<N;i++){
        int x;
        scanf("%d", &x);
        vc.push_back(x);
    }
    sort(vc.begin(), vc.end());
    vector<int> a, b;
    for(int i=0;i<(int)vc.size();i++){
        if(i & 1)
            a.push_back(vc[i]);
        else 
            b.push_back(vc[i]);
    }
    for(int i=(int)b.size()-1;i>=0;i--)
        a.push_back(b[i]);
    int ans = 0;
    for(int i=0;i<(int)a.size();i++){
        ans = max(ans, abs(a[i] - a[(i+1)%a.size()]));
    }
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
