#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
int cmp(ll x){
	if(x == 0) return 0;
	if(x > 0) return 1;
	else return -1;
}
struct Point{
    ll x, y;
	Point operator - (const Point &rhs) const {
		return {x - rhs.x, y - rhs.y};
	}
	ll Cross(const Point &rhs) const {
		return (x * rhs.y - y * rhs.x);
	}
};
struct Line{
    Point a, b;
	bool IsIntersect(const Line &rhs){
		if(cmp((rhs.a - a).Cross(rhs.b - a) * (rhs.a - b).Cross(rhs.b - b)) > 0) 
			return false;
		if(cmp((a - rhs.a).Cross(b - rhs.a) * (a - rhs.b).Cross(b - rhs.b)) > 0) 
			return false;
		return true;
	}
}l[20];
struct Circle{
    Point O;
    ll R;
    bool InCircle(const Point a){
        return sqr(R) >= sqr(a.x - O.x) + sqr(a.y - O.y);
    }
}c[250010];
map<int, int> mp[20100];
int s, r, w, p;
#define OFFSET 10020
void Solve(){
    for(int i=0;i<=20050;i++)
        mp[i].clear();
    scanf("%d%d%d%d", &s, &r, &w, &p);
    for(int i=0;i<s;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        x += OFFSET, y += OFFSET;
        c[i] = {{(ll)x, (ll)y}, (ll)r};
        mp[x][y] = i;
    }
    for(int i=0;i<w;i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1 += OFFSET, x2 += OFFSET, y1 += OFFSET, y2 += OFFSET;
        l[i] = {{(ll)x1, (ll)y1}, {(ll)x2, (ll)y2}};
    }
    for(int i=0;i<p;i++){
        vector<int> ans;
        int x, y;
        scanf("%d%d", &x, &y);
        x += OFFSET, y += OFFSET;
        for(int j=max(0, x - r);j<=min(OFFSET * 2, x + r);j++){
            //printf("j %d\n", j);
            auto it = mp[j].lower_bound(y - r);
            while(it != mp[j].end() && abs(it->first - y) <= r){
                int id = it->second;
                //printf("test %d %d\n", i, id);
                if(c[id].InCircle({x, y})){
                    //printf("in %d %d\n", i, id);
                    Line toc = {{x, y}, c[id].O};
                    int intersect = 0;
                    for(int k=0;k<w;k++){
                        //if(l[k].Parallel(toc))continue;
                        if(l[k].IsIntersect(toc))intersect++;
                    }
                    //printf("inter %d\n", intersect);
                    if(Circle({c[id].O, max(0ll, c[id].R - intersect)}).InCircle({x, y}))
                        ans.push_back(id);
                }
                ++it;
            } 
        }
        printf("%d", (int)ans.size());
        for(int id : ans){
            printf(" (%d,%d)", (int)c[id].O.x - OFFSET, (int)c[id].O.y - OFFSET);
        }
        puts("");
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
