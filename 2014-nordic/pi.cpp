#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9 
#define INF 1e9
const double PI = acos(-1);
int cmp(double x){
	if(fabs(x) < EPS) return 0;
	if(x > 0) return 1;
	else return -1;
}
struct Point{
	double x ,y;
	Point(double _x=0, double _y=0): x(_x), y(_y) {}
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
struct Line{
	Point a, b;
	Line(Point _a=Point(), Point _b=Point()): a(_a), b(_b) {}
	double Dist(const Point &rhs){
		//if(cmp((rhs - a).Dot(b - a)) < 0) return (rhs - a).Abs();
		//if(cmp((rhs - b).Dot(a - b)) < 0) return (rhs - b).Abs();
		return fabs((a - rhs).Cross(b - rhs) / a.Dist(b));
	}
	/*
	 * the pedal of rhs on line
	 */
	Point Proj(const Point &rhs){
		double r = (a - b).Dot(rhs - b) / (a - b).Dot(a - b);
		return b + (a - b) * r;
	}
	bool OnLine(const Point &rhs){
		return cmp((rhs - b).Cross(a - b)) == 0;
	}
	bool OnSegment(const Point &rhs){
		return cmp((rhs - b).Cross(a - b)) == 0 && cmp((rhs - b).Dot(rhs - a)) <= 0;
	}
	bool Parallel(const Line &rhs){
		return !cmp((a - b).Cross(rhs.a - rhs.b));
	}
	//for segment
	bool IsIntersect(const Line &rhs){
		if(cmp((rhs.a - a).Cross(rhs.b - a) * (rhs.a - b).Cross(rhs.b - b)) > 0) 
			return false;
		if(cmp((a - rhs.a).Cross(b - rhs.a) * (a - rhs.b).Cross(b - rhs.b)) > 0) 
			return false;
		return true;
	}
	/* default is line */
	Point Intersection(const Line &rhs, bool flag=false){
		if(Parallel(rhs)) return nilPoint;
		/* for segment */
		if(flag && IsIntersect(rhs) == false) return nilPoint;
		/* end */
		double s1 = (a - rhs.a).Cross(rhs.b - rhs.a);
		double s2 = (b - rhs.a).Cross(rhs.b - rhs.a);
		return (b * s1 - a * s2) / (s1 - s2);
	}
	/*
	 * move d units along the direction of line
	 * example: {(0, 0) -> (1, 1)} move _/2 becomes {(1, 1) -> (2, 2)}
	 */
	Line Move(const double &d){
		Point tmp = b - a;
		tmp = tmp / tmp.Abs();
		return Line(a + tmp * d, b + tmp * d);
	}

	friend ostream& operator << (ostream &out, const Line &rhs){
		out << "[" << rhs.a << ", " << rhs.b << "]";
		return out;
	}
}nilLine(nilPoint, nilPoint);
map<int, map<int, vector<Line>>> lines;
map<int, map<int, vector<pair<double, int>>>> distances;
int calc(const vector<pair<double, int>> &s, const pair<double, int> &p){
    int l = 0, r = s.size() - 1;
    while(r >= l){
        int mid = (l + r) >> 1;
        int res = cmp(s[mid].first - p.first);
        if(res == 0){
            return s[mid].second * p.second;
        }else if(res > 0){
            r = mid - 1;
        }else if(res < 0){
            l = mid + 1;
        }
    }
    return 0;
}
int main(){
    //int a, b;
    //while(~scanf("%d%d", &a, &b))
        //printf("%d\n", __gcd(a, b));
    int N;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int dx = x1 - x2, dy = y1 - y2;
        int dg = __gcd(dx, dy);
        dx /= dg, dy /= dg;
        if(dx * dy < 0){
            dx = abs(dx);
            dy = -abs(dy); 
        }
        lines[dx][dy].push_back(Line(Point(x1, y1), Point(x2, y2)));
    }
    for(auto &x : lines){
        for(auto &y : x.second){
            int dx = x.first, dy = y.first;
            vector<double> tmp;
            for(int i = 0 ; i < (int)y.second.size() ; i++){
                for(int j = i + 1 ; j < (int)y.second.size() ; j++){
                    tmp.push_back(y.second[i].Dist(y.second[j].a));
                }
            }
            sort(tmp.begin(), tmp.end());
            vector<pair<double, int>> tmp2;
            for(int i = 0 ; i < (int)tmp.size() ; i++){
                if(tmp2.size() == 0){
                    tmp2.push_back({tmp[i], 1});
                }else{
                    if(cmp(tmp[i] - tmp2.back().first) == 0){
                        tmp2.back().second++;
                    }else{
                        tmp2.push_back({tmp[i], 1});
                    }
                }
            }
            distances[dx][dy] = tmp2;
        }
    }
    int ans = 0;
    for(auto &x : distances){
        for(auto &y : x.second){
            int dx = x.first, dy = y.first;
            int ddx = dy, ddy = dx;
            if(ddx && ddy)
                ddx = -ddx;
            if(ddx * ddy < 0){
                ddx = abs(ddx);
                ddy = -abs(ddy);
            }
            int p1 = 0, p2 = 0;
            while(true){
                if(p1 >= (int)distances[dx][dy].size())break;
                if(p2 >= (int)distances[ddx][ddy].size())break;
                int res = cmp(distances[dx][dy][p1].first - distances[ddx][ddy][p2].first);
                if(res == 0){
                    ans += distances[dx][dy][p1].second * distances[ddx][ddy][p2].second;
                    p1++, p2++;
                }else if(res < 0){
                    p1++;
                }else{
                    p2++;
                }
            }
            //for(auto &p : y.second){
                //int tmp = calc(distances[dx][dy], p);
                //ans += tmp;
            //}
        }
    }
    printf("%d\n", ans / 2);
    return 0;
}
