#include <bits/stdc++.h>
using namespace std;
#define sqr(x) ((x)*(x))
int x[110], y[110], r[110];
struct Seg{
    int sum, lazy, val, l, r;
}s[20000<<3];
void up(int x){
    s[x].sum = s[x*2].sum + s[x*2+1].sum; 
}
void down(int x){
    if(s[x].lazy){
        s[x].lazy = 0;
        s[x*2].val = s[x].val;
        s[x*2].sum = (s[x*2].r - s[x*2].l + 1)  * s[x*2].val;
        s[x*2].lazy = 1;
        s[x*2+1].val = s[x].val;
        s[x*2+1].sum = (s[x*2+1].r - s[x*2+1].l + 1)  * s[x*2+1].val;
        s[x*2+1].lazy = 1;
    }
}
void build(int id, int l, int r){
    s[id].l = l, s[id].r = r, s[id].lazy = s[id].sum = s[id].val = 0;
    if(l == r){
        return;
    }
    int mid = (l + r) >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
}
void update(int id, int l, int r, int v){
    //printf("%d %d %d %d %d %d %d %d\n", id, s[id].l, s[id].r, s[id].val, s[id].sum, l ,r, v);
    //printf("---%d %d %d %d %d %d %d\n", id*2+1, s[id*2+1].l, s[id*2+1].r, s[id*2+1].sum, l ,r, v);
    down(id);
    if(s[id].l == l && s[id].r == r){
        s[id].lazy = 1;
        s[id].val = v;
        s[id].sum = v * (r - l + 1);
        return;
    }
    int mid = (s[id].l + s[id].r) >> 1;
    if(r <= mid){
        update(id*2, l, r, v);
    }else if(l > mid){
        update(id*2+1, l, r, v);
    }else{
        update(id*2, l, mid, v);
        update(id*2+1, mid + 1, r, v);
    }
    up(id);
    //printf("up %d %d %d %d\n", id, s[id].l, s[id].r, s[id].sum);
}
int main(){
    freopen("circles.in", "r", stdin);
    freopen("circles.out", "w", stdout);
    int W, H, N;
    scanf("%d%d%d", &W, &H, &N);
    build(1, 0, H);
    for(int i=0;i<N;i++)
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
    int ans = 0;
    for(int i=0;i<W;i++){
        update(1, 0, H-1, 0);
        for(int j=0;j<N;j++){
            int d = abs(x[j] - i);
            int y2 = sqr(r[j]) - sqr(d);
            if(y2 < 0)continue;
            int y1 = sqrt(y2);
            update(1, max(y[j] - y1, 0), min(y[j] + y1, H - 1), 1);
        }
        ans += s[1].sum;
    }
    printf("%d\n", W * H - ans);
    return 0;
}
