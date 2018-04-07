#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int c[100010];
int ans[100010];
int main(){
    freopen("G.IN", "r", stdin);
    int n, h, b, e;
    while(~scanf("%d%d%d%d", &n, &h, &b, &e)){
        memset(ans, 0, sizeof(ans));
        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &c[i]);
        }
        set<PII> st;
        int l = n;
        memset(ans, 0, sizeof(ans));
        for(int i = n ; i >= 1 ; i--){
            while(l >= 1 && i - h + 1 <= l){
                st.insert({c[l], -l});
                l--;
            }
            ans[-st.begin()->second]++;
            st.erase({c[i], -i});
        }
        for(int i = b ; i <= e ; i++){
            if(i != b)printf("\t");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
