#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef pair<PII, int> PPI;
map<int, PPI> default_ans;
int _next[8];
int d[2] = {1, -1};

void Next(int x){
    int src[4];
    for(int i = 0 ; i < 4 ; i++){
        src[i] = x % 10;
        x /= 10;
    }
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            src[i] = (src[i] + d[j] + 10) % 10;
            int calc = 0;
            for(int k = 3 ; k >= 0 ; k--)
                calc = calc * 10 + src[k];
            _next[2*i+j] = calc;
            src[i] = (src[i] - d[j] + 10) % 10;
        }
    }
}

bool isvalid(int x){
    bool use[10] = {};
    for(int i = 0 ; i < 4 ; i++){
        int r = x % 10;
        x /= 10;
        if(use[r]) return false;
        use[r] = true;
    }
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        queue< PII > Q;
        int start;
        scanf("%d", &start);
        if(default_ans[start].first.first){
            printf("%d %d %04d\n", default_ans[start].first.first,
                    default_ans[start].first.second,
                    default_ans[start].second);
            continue;
        }
        int step = 0;
        int ans = 0;
        int min_ans = 10000;
        bool visit[10000] = {};
        visit[start] = 1;
        Q.push(PII(start, 0));
        while(Q.size()){
            PII now = Q.front();
            Q.pop();
            if(ans && step < now.second)
                continue;
            if(isvalid(now.first)){
                ans++;
                step = now.second;
                min_ans = min(min_ans, now.first);
            }
            if(ans) continue;
            Next(now.first);
            for(int i = 0 ; i < 8 ; i++){
                if(visit[_next[i]])
                    continue;
                Q.push(PII(_next[i], now.second + 1));
                visit[_next[i]] = 1;
            }
        }
        default_ans[start] = PPI(PII(ans, step), min_ans);
        printf("%d %d %04d\n", ans, step, min_ans);
    }
    return 0;
}
