#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
int N, Q;
int a[MAXN];
struct Seg{
    double val, a, b;
    int len;
}seg[MAXN << 2];
void build(int id, int l, int r){
    seg[id].len = r - l + 1;
    seg[id].a = 1;
    seg[id].b = 0;
    if(l == r){
        seg[id].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build((id << 1) | 1, mid + 1, r);
    seg[id].val = seg[id << 1].val + seg[(id << 1) | 1].val;
    //printf("%f\n", seg[id].val);
}
void modify(int id, double a, double b){
    seg[id].a *= a;
    seg[id].b = seg[id].b * a + b;
    seg[id].val = seg[id].val * a + b * seg[id].len;
    //printf("%d %f %f %f\n", id, seg[id].val, a, b);
}
void down(int id){
    modify(id << 1, seg[id].a, seg[id].b);
    modify((id << 1) | 1, seg[id].a, seg[id].b);
    seg[id].a = 1, seg[id].b = 0;
}
void update(int id, int l, int r, int ul, int ur, double a, double b){
    //printf("%d %d %d\n", id, l, r);
    if(ul > r || ur < l) return;
    if(ul <= l && r <= ur){
        modify(id, a, b);
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, ul, ur, a, b);
    update((id << 1) | 1, mid + 1, r, ul, ur, a, b);
    seg[id].val = seg[id << 1].val + seg[(id << 1) | 1].val;
    //printf("%f\n", seg[id].val);
}
double query(int id, int l, int r, int ql, int qr){
    //printf("%d %d %d %d %d\n", id, l, r, ql, qr);
    if(ql > r || qr < l) return 0;
    if(ql <= l && r <= qr) return seg[id].val;
    down(id);
    int mid = (l + r) >> 1;
    return query(id << 1, l, mid, ql, qr) + query((id << 1) | 1, mid + 1, r, ql, qr);
}
int main(){
    scanf("%d%d", &N, &Q);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &a[i]);
    build(1, 0, N - 1);
    while(Q--){
        int op;
        scanf("%d", &op);
        if(op == 1){
            int l1, r1, l2, r2;
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            l1--, r1--, l2--, r2--;
            double d1 = r1 - l1 + 1, d2 = r2 - l2 + 1;
            double q1 = query(1, 0, N - 1, l1, r1), q2 = query(1, 0, N - 1, l2, r2);
            //printf("qq %f %f\n", q1, q2);
            update(1, 0, N - 1, l1, r1, (double)(d1 - 1) / d1, (double)q2 / d1 / d2);
            update(1, 0, N - 1, l2, r2, (double)(d2 - 1) / d2, (double)q1 / d1 / d2);
        }else{
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            printf("%.7f\n", query(1, 0, N - 1, l, r));
        }
    }
    return 0;
}
