#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
char s[1010], e[1010];
char _s[1010];
int t[1010];
struct Sta{
    int idx, v;
    Sta(int _i=0, int _v=0): idx(_i), v(_v){}
    bool operator < (const Sta &n) const {
        return v < n.v;
    }
};
int cas = 0;
ll diff;
ll trans(int idx){
    if(_s[idx] == '0'){
        _s[idx] = '1';
        diff += t[idx];
    }
    else {
        _s[idx] = '0';
        diff -= t[idx];
    }
    return diff;
}
Sta tmp[1010];
bool Solve(){
    vector<Sta> z2z, o2z, z2o, z;
    scanf("%d", &N);
    if(!N)return false;
    scanf("%s%s", s, e);
    for(int i=0;i<N;i++)
        scanf("%d", &t[i]);
    int tdiff = 0;
    for(int i=0;i<N;i++){
        tdiff += (s[i] - '0') * t[i];
        if(s[i] == '0' && e[i] == '1')
            o2z.push_back(Sta(i, t[i]));
        if(s[i] == '1')
            z.push_back(Sta(i, t[i]));
    }
    sort(z.begin(), z.end());
    sort(o2z.begin(), o2z.end());
    reverse(z.begin(), z.end());
    ll ans = LLONG_MAX;
    vector<Sta> _z2o, _z2z, _o2z;
    for(int l=0;l<=(int)z.size();l++){
        diff = tdiff;
        memcpy(_s, s, sizeof(s));
        ll tans = 0;
        int k = 0;
        int cnt = 0;
        for(Sta x: z){
            if(e[x.idx] == '0')
                tans += trans(x.idx);
            else if(k < l){
                tans += trans(x.idx);
                tmp[cnt++] = x;
                k++;
            }
        }
        int now = cnt-1;
        for(Sta x: o2z){
            while(now >= 0 && tmp[now].v < x.v){
                tans += trans(tmp[now].idx);
                now--;
            }
            tans += trans(x.idx);
        }
        while(now >= 0){
            tans += trans(tmp[now].idx);
            now--;
        }
        ans = min(ans, tans);
    }
    printf("Case %d: %lld\n", ++cas, ans);
    return true;
}
int main(){
    while(Solve());
    return 0;
}
