#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-6 
#define INF 1e9
const double PI = acos(-1);
int cmp(double x){
	if(fabs(x) < EPS) return 0;
	if(x > 0) return 1;
	else return -1;
}
struct Point{
	int x ,y;
	Point(int _x=0, int _y=0): x(_x), y(_y) {
        int d = __gcd(x, y);
        if(d == 0)return;
        x /= d;
        y /= d;
    }
	Point operator + (const Point &rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	Point operator - (const Point &rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	Point operator * (const double &rhs) const {
		return Point(x * rhs, y * rhs);
	}
	Point operator / (const double &rhs) const {
		return Point(x / rhs, y / rhs);
	}
	bool operator == (const Point &rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	double Abs() const {
		return sqrt(Dot(*this));
	}
	/*
	 * range: 0 ~ 2*PI
	 */
	double Arg() const {
		double res = atan2(y, x);
		if(cmp(res) < 0) res += PI * 2.0;
		return res;
	}
	double Dot(const Point &rhs) const {
		return (x * rhs.x + y * rhs.y);
	}
	double Cross(const Point &rhs) const {
		return (x * rhs.y - y * rhs.x);
	}
	double Dist(const Point &rhs) const {
		return (*this - rhs).Abs();
	}
	/*
	 * unit of d is radian(counterclockwise)
	 */
	Point Rotate(double d) const {
		return Rotate(cos(d), sin(d));
	}
	Point Rotate(double cost, double sint) const {
		return Point(x * cost - y * sint, x * sint + y * cost);
	}
	bool operator < (const Point &rhs) const {
		if(x == rhs.x)
			return y < rhs.y;
		return x < rhs.x;
	}
	friend ostream& operator << (ostream &out, const Point &rhs){
		out << "(" << rhs.x << ", " << rhs.y << ")";
		return out;
	}
	Point& update(){
		if(cmp(x) == 0) x = 0;
		if(cmp(y) == 0) y = 0;
		return *this;
	}
}nilPoint(INF, INF);

struct Rect{
    int x1, x2, y1, y2;
};

struct Seg{
    Point p;
    int id, in;
};

void Solve(){
    int N;
    scanf("%d", &N);
    vector<Rect> r;
    vector<Seg> seg;
    for(int i = 0 ; i < N ; i++){
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        r.push_back({x1, x2, y1, y2});
        vector<Point> ttmp = {{x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}};
        vector<Point> tmp;
        for(int i = 0 ; i < 4 ; i++){
            if(ttmp[i].x || ttmp[i].y)
                tmp.push_back(ttmp[i]);
        }
        sort(tmp.begin(), tmp.end(), [](const Point &a, const Point &b){return a.Arg() < b.Arg();});
        seg.push_back({tmp.front(), i, 1});
        seg.push_back({tmp.back(), i, -1});
    }
    sort(seg.begin(), seg.end(), [](const Seg &a, const Seg &b){
            if(a.p.x == b.p.x && a.p.y == b.p.y){
            return a.in > b.in;
            }
            return a.p.Arg() < b.p.Arg();
            });
    int now = 0, ans = 0;
    Point pans;
    for(int i = 0 ; i < 2 * N ; i++){
        if(seg[i].in > 0)
            now += seg[i].in; 
        //cout << seg[i].p << "" << now << endl;
        if(now > ans){
            ans = now;
            pans = seg[i].p;
        } else if(now == ans){
            if((double)seg[i].p.y / (double)seg[i].p.x > (double)pans.y / (double)pans.x){
                pans = seg[i].p;
            }
        }
        if(seg[i].in < 0)
            now += seg[i].in; 
    }
    if(pans.x == 0)pans.y == 1;
    else if(pans.y == 0)pans.x = 1;
    printf("%d/%d %d\n", pans.y, pans.x, ans);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
