#include <bits/stdc++.h>
using namespace std;
#define HASH_SIZE 181081
#define C 131
char s[10000];
char new_s[510][510];
deque<char> h[HASH_SIZE];
int nh[2][510];
int cmp[510][510];
int N;
int iidx[510];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        int M;
        scanf("%d %d", &N, &M);
        for(int i=0;i<N;i++)
            scanf("%d", &iidx[i]);
        for(int i=0;i<HASH_SIZE;i++)
            h[i].clear();
        memset(nh, 0, sizeof(nh));
        int len = strlen(s), num = 0, now = 0;
        for(int i=0;i<len;i++){
            new_s[now][0] = s[i];
            h[0].push_back(s[i]);
            now ++;
        }
        sort(h[0].begin(), h[0].end());
        for(int i=1;i<now;i++){
            set<int> use;
            for(int j=0;j<now;j++){
                new_s[j][i] = h[nh[1][j]].front();
                h[nh[1][j]].pop_front();
                nh[0][j] = (nh[0][j] * C + new_s[j][i-1]) % HASH_SIZE;
                nh[1][j] = (nh[1][j] * C + new_s[j][i]) % HASH_SIZE;
                h[nh[0][j]].push_back(new_s[j][i]);
                use.insert(nh[0][j]);
            }
            for(int u: use)
                sort(h[u].begin(), h[u].end());
        }
        for(int i=0;i<now;i++){
            for(int j=0;j<now;j++){
                cmp[i][j] = strncmp(new_s[i], new_s[j], now);
            }
        }
        vector<int> idx;
        for(int i=0;i<now;i++)
            idx.push_back(i);
        sort(idx.begin(), idx.end(), [&](const int &a, const int &b){return cmp[a][b] < 0;});
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                printf("%c", new_s[idx[iidx[i]-1]][j]);
            }
        }
    }
    return 0;
}
