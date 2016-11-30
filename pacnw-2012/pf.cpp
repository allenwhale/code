#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-8
#define INF 1e9
const double PI = acos(-1);
int cmp(double x){
    if(fabs(x) < EPS) return 0;
    if(x > 0) return 1;
    else return -1;
}
struct Point{
    double x, y;
    Point operator + (const Point &n) const {
        return {x + n.x, y + n.y};
    }
    Point operator - (const Point &n) const {
        return {x - n.x, y - n.y};
    }
    Point operator / (double n) const {
        return {x / n, y / n};
    }
    double Arg() const {
        double res = atan2(y, x);
        if(cmp(res) < 0) res += PI * 2.0;
        return res;
    }
    double Abs() const {
        return sqrt(x * x + y * y);
    }
    double Dist(const Point &n) const {
        return (*this - n).Abs();
    }
    double Cross(const Point &n) const {
        return x * n.y - y * n.x;   
    }
    bool operator == (const Point &n) const {
        return cmp(x - n.x) == 0 && cmp(y - n.y) == 0;
    }
    bool operator < (const Point &n) const {
        return Arg() < n.Arg();
    }
};
struct Circle{
    Point O;
    double R;
    Circle(const Point &o, const double &r): O(o), R(r) {}
    bool InCircle(const Point &rhs) const {
        return cmp(O.Dist(rhs) - R) < 0;
    }
    bool OnCircle(const Point &rhs) const {
        return cmp(O.Dist(rhs) - R) == 0;
    };
};
Circle Center(const Point &rhs1, const Point &rhs2){
    return Circle((rhs1+rhs2)/2.0, rhs1.Dist(rhs2)/2.0);
}
Circle Center(const Point &rhs1, const Point &rhs2, const Point &rhs3){
    Circle res(rhs1, 0);
    Point d1 = rhs2 - rhs1, d2 = rhs3 - rhs1;
    double c1 = (d1.x * d1.x + d1.y * d1.y) / 2.0, 
           c2 = (d2.x * d2.x + d2.y * d2.y) / 2.0;
    double d = d1.Cross(d2);
    res.O.x += (c1 * d2.y - c2 * d1.y) / d;
    res.O.y += (c2 * d1.x - c1 * d2.x) / d;
    res.R = res.O.Dist(rhs1);
    return res;
}
Circle MinCircleCover(vector<Point> rhs){
    random_shuffle(rhs.begin(), rhs.end());
    Circle res(rhs[0], 0);
    for(int i=1;i<(int)rhs.size();i++){
        if(!res.InCircle(rhs[i])){
            res = Circle(rhs[i], 0);
            for(int j=0;j<i;j++){
                if(!res.InCircle(rhs[j])){
                    res = Center(rhs[i], rhs[j]);
                    for(int k=0;k<j;k++){
                        if(!res.InCircle(rhs[k])){
                            res = Center(rhs[i], rhs[j], rhs[k]);
                        }
                    }
                }
            }
        }
    }
    return res;
}
Circle MinCircleCover2(vector<Point> rhs, const Point &n){
    random_shuffle(rhs.begin(), rhs.end());
    Circle res(n, 0);
    for(int j=0;j<(int)rhs.size();j++){
        if(!res.InCircle(rhs[j])){
            res = Center(n, rhs[j]);
            for(int k=0;k<j;k++){
                if(!res.InCircle(rhs[k])){
                    res = Center(n, rhs[j], rhs[k]);
                }
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    string str[2];
    while(getline(cin, str[0])){
        vector<Point> p[2];
        getline(cin, str[1]);
        for(int i = 0 ; i < 2 ; i++){
            stringstream s(str[i]);
            string buf;
            s >> buf;
            while(s >> buf){
                if(buf == string("none")){
                } else {
                    double x, y;
                    sscanf(buf.c_str(), "(%lf,%lf)", &x, &y);
                    p[i].push_back({x, y});
                }
            }
        }
        if(p[0].size() == 0){
            printf("%d\n", 0);
            continue;
        }
        Circle c = MinCircleCover(p[0]);
        bool ans = true;
        double ansR = 1e15;
        for(auto x : p[1]){
            if(c.InCircle(x) || c.OnCircle(x)){
                ans = false;
            }
        }
        if(ans){
            printf("%.15f\n", c.R);
            continue;
        }
        for(auto x : p[1]){
            c = MinCircleCover2(p[0], x);
            bool ok = true;
            for(auto y : p[1]){
                if(c.InCircle(y)){
                    ok = false;
                }
            }
            if(!ok)continue;
            ok = false;
            vector<pair<double, int>> tmp;
            int bad_cnt = 0;
            for(auto y : p[1]){
                if(c.OnCircle(y)){
                    tmp.push_back({(y - c.O).Arg(), 1});
                    bad_cnt++;
                }
            }
            for(auto y : p[0]){
                if(c.OnCircle(y))
                    tmp.push_back({(y - c.O).Arg(), 0});
            }
            sort(tmp.begin(), tmp.end());
            int sz = tmp.size();
            for(int i=0;i<sz;i++){
                tmp.push_back(tmp[i]);
                tmp.back().first += 2 * PI;
            }
            for(int i=0;i<sz;i++){
                int cnt = 0;
                for(int j=0;j<bad_cnt&&i+j<(int)tmp.size();j++){
                    if(tmp[i+j].second == 0)break;
                    cnt++;
                }
                if(cnt == bad_cnt){
                    if(cmp((tmp[i+bad_cnt-1].first - tmp[i].first) - PI) < 0){
                        ok = true;
                        break;
                    }
                }
            }
            if(ok){
                ans = true;
                ansR = min(ansR, c.R); 
            }
        }
        if(ans){
            printf("%.15f\n", ansR);
        }else{
            printf("The Orcs are close\n");
        }
    }
    return 0;
}
