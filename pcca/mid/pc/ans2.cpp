#include <bits/stdc++.h>
using namespace std;
#define MAXN 362880
int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
vector<int> now(9);
void decode(int x, int n){
    vector<bool> used(n+1, false);
    for(int i=0;i<n;i++){
        int tmp = x / factorial[n-i-1];
        int j;
        for(j=1;j<=n;j++)if(!used[j]){
            if(tmp == 0) break;
            tmp--;
        }
        now[i] = j - 1, used[j] = true;
        x %= factorial[n-i-1];
    }
}
int encode(const vector<int>& a){
    int res = 0;
    for(int i=0;i<(int)a.size();i++){
        int tmp = a[i];
        for(int j=0;j<i;j++)
            if(a[j] < a[i]) tmp--;
        res += factorial[(int)a.size()-i-1] * tmp;
    }
    return res;
}

int dist[2][MAXN+10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isin(int x, int y){
    return x >= 0 && y >= 0 && x < 3 && y < 3;
}
bool solvable(const vector<int> &a){
    int sum = 0;
    for(int i=0;i<(int)a.size();i++){
        for(int j=i+1;j<(int)a.size();j++){
            if(a[j] == 0)continue;
            sum += a[i] > a[j];
        }
    }
    return (sum%2) == 0;
}
int Solve(){
    memset(dist, 0x3f, sizeof(dist));
    vector<int> start(9), target(9);
    for(int i=0;i<9;i++)
        scanf("%d", &start[i]);
    int start_t = encode(start);
    //printf("start_t %d\n", start_t);
    for(int i=0;i<9;i++){
        scanf("%d", &target[i]);
    }
    if(solvable(start) != solvable(target)) return -1;
    int target_t = encode(target);
    if(start_t == target_t) return 0;
    dist[0][start_t] = 0;
    dist[1][target_t] = 0;
    queue<int> q[2];
    q[0].push(start_t);
    q[1].push(target_t);
    int ans = -1;
    while(!q[0].empty() && !q[1].empty() && ans == -1){
        for(int k=0;k<2;k++){
            int now_t = q[k].front(); q[k].pop();
            //printf("now_t %d\n", now_t);
            decode(now_t, 9);
            int zero = 0;
            for(int i=0;i<9;i++)
                if(now[i] == 0)
                    zero = i;
            int nx = zero / 3, ny = zero % 3;
            for(int i=0;i<4;i++){
                int tx = nx + dx[i], ty = ny + dy[i];
                if(isin(tx, ty) == false) continue;
                vector<int> next = now;
                swap(next[zero], next[tx*3+ty]);
                int next_t = encode(next);
                if(dist[k][next_t] != 0x3f3f3f3f) continue;
                dist[k][next_t] = dist[k][now_t] + 1;
                if(dist[k^1][next_t] != 0x3f3f3f3f){
                    ans = dist[k][next_t] + dist[k^1][next_t];
                    break;
                }
                q[k].push(next_t);
            }
        }
    }
    return ans;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        printf("%d\n", Solve());
    }
    return 0;
}
