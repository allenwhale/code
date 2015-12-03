#include <bits/stdc++.h>
using namespace std;
int mp[310][310];
int N;
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d", &mp[i][j]);
    int Q;
    scanf("%d", &Q);
    while(Q--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        if(c < mp[a][b]){
            mp[a][b] = mp[b][a] = c;
            for(int i=0;i<N;i++)
                for(int j=i+1;j<N;j++){
                    mp[i][j] = mp[j][i] = min(mp[i][j], mp[i][a] + c + mp[b][j]);
                    mp[i][j] = mp[j][i] = min(mp[i][j], mp[j][a] + c + mp[b][i]);
                }
        }
        int ans = 0;
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                ans += mp[i][j];
        printf("%d ", ans);
    }
    puts("");
    return 0;
}

