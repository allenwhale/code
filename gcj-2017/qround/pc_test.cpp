#include <bits/stdc++.h>
using namespace std;

struct interval {
    int l, r;
    bool operator < (const interval &n) const {
        if(n.r - n.l == r - l)
            return n.l < l;
        return (n.r - n.l) > (r - l);
    }
};


void Solve() {
    int N, K;
    scanf("%d%d", &N, &K);
    priority_queue<interval> pq;
    pq.push({1, N});
    int mn = INT_MAX, mx = INT_MIN;
    while(K--) {
        interval now = pq.top();
        pq.pop();
        int mid = (now.l + now.r) >> 1;
        if(now.l <= mid - 1)
            pq.push({now.l, mid - 1});
        if(mid + 1 <= now.r)
            pq.push({mid + 1, now.r});
        mn = min(mid - now.l, now.r - mid);
        mx = max(mid - now.l, now.r - mid);
    }
    printf("%d %d\n", mx, mn);
}


int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1 ; t <= T ; t++) {
        printf("Case #%d: ", t);
        Solve();
    }
    return 0;
}
