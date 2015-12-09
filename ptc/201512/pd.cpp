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
int main(){
    while(~scanf("%s%d", s, &N)){
        if(strcmp(s, "END") == 0) break;
        for(int i=0;i<HASH_SIZE;i++)
            h[i].clear();
        memset(nh, 0, sizeof(nh));
        int len = strlen(s), num = 0, now = 0;
        for(int i=0;i<len;i++){
            if(isdigit(s[i])){
                num = num * 10 + s[i] - '0';
            }else{
                for(int j=0;j<num;j++,now++){
                    new_s[now][0] = s[i];
                    h[0].push_back(s[i]);
                }
                num = 0;
            }
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
        }
        for(int i=0;i<now;i++)
            s[i] = new_s[N-1][i];
        reverse(s, s+now);
        for(int i=0;i<now;i++){
            for(int j=0;j<now;j++){
                new_s[i][j] = s[(i+j)%now];
            }
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
        num = 0;
        char last = new_s[idx[0]][now-1];
        for(int i=0;i<now;i++){
            if(new_s[idx[i]][now-1] == last){
                num ++;
            }else{
                printf("%d%c", num, last);
                last = new_s[idx[i]][now-1];
                num = 1;
            }
        }
        printf("%d%c\n", num, last);
    }
    return 0;
}
