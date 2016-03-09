#include <bits/stdc++.h>
using namespace std;
#define MAXN 362880
typedef pair<int, int> PI;
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

int dist[MAXN+10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
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
bool isin(int x, int y){
    return x >= 0 && y >= 0 && x < 3 && y < 3;
}
int Solve(){
    memset(dist, 0x3f, sizeof(dist));
    vector<int> start(9);
    int zero = 0;
    for(int i=0;i<9;i++){
        scanf("%d", &start[i]);
        if(start[i] == 0) zero = i;
    }
    if(solvable(start) == false) return -1;
    int start_t = encode(start);
    int target_t = encode({1, 2, 3, 4, 5, 6, 7, 8, 0});
    dist[start_t] = 0;
    queue<PI> q;
    q.push({start_t, zero});
    int mx = 0, cnt = 0;
    while(!q.empty()){
        cnt++;
        int now_t = q.front().first;
        zero = q.front().second;
        q.pop();
        mx = max(mx, dist[now_t]);
        if(now_t == target_t)
            break;
        decode(now_t, 9);
        int nx = zero / 3, ny = zero % 3;
        for(int i=0;i<4;i++){
            int tx = nx + dx[i], ty = ny + dy[i];
            if(isin(tx, ty) == false) continue;
            vector<int> &next = now;
            swap(next[zero], next[tx*3+ty]);
            int next_t = encode(next);
            if(dist[next_t] == 0x3f3f3f3f){
                dist[next_t] = dist[now_t] + 1;
                q.push({next_t, tx*3+ty});
            }
            swap(next[zero], next[tx*3+ty]);
        }
    }
    //printf("mx %d, cnt %d\n", mx, cnt);
    return dist[target_t] != 0x3f3f3f3f ? dist[target_t] : -1; 
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        printf("%d\n", Solve());
    }
    return 0;
}
