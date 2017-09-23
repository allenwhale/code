#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum[100010], q[100010];
double get(int a, int b){
    return double(sum[b] - sum[a]) / double(b - a);
}
bool cmp(double a, double b){
    return a < b || abs(a - b) < 1e-6;
}
void Solve(){
    int N, L;
    scanf("%d%d", &N, &L);
    sum[0] = 0;
    for(int i = 1 ; i <= N ; i ++){
        int x;
        scanf("%1d", &x);
        sum[i] = sum[i - 1] + x;
    }
    int st = 0, ed = N;
    double ans = double(sum[N]) / double(N);
    int front = 0, rear = -1;
    for(int i = L ; i <= N ; i++){
        int l = i - L;
        while(front < rear && cmp(get(q[rear], l), get(q[rear - 1], q[rear])))
            rear--;
        q[++rear] = l;
        while(front < rear && cmp(get(q[front], i), get(q[front + 1], i)))
            front++;
        double now = get(q[front], i);
        if(now > ans || ((now == ans) && ed - st > i - q[front])){
            ans = now;
            st = q[front];
            ed = i;
        }
    }
    printf("%d %d\n", st + 1, ed);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
