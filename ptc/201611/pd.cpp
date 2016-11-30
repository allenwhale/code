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
		if(cmp((rhs - a).Dot(b - a)) < 0) return (rhs - a).Abs();
		if(cmp((rhs - b).Dot(a - b)) < 0) return (rhs - b).Abs();
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
struct Circle{
	Point O;
	double R;
    Circle(){
        R = 0;
    }
	Circle(const Point &o, const double &r): O(o), R(r) {}
	double Area() const {
		return PI * R * R;
	}
	double Perimeter() const {
		return 2.0 * PI * R;
	}
	/*
	 * default not includes on the edge
	 */
	bool InCircle(const Point &rhs) const {
		return cmp(O.Dist(rhs) - R) < 0;
	}
	/*
	 * default is segment
	 * if want to change it to line, remove the if which judge t
	 */
	vector<Point> Intersection(const Line &rhs){
		vector<Point> res;
		Point d1 = rhs.b - rhs.a, d2 = rhs.a - O; 
		double A = d1.x * d1.x + d1.y * d1.y;
		double B = 2.0 * d1.Dot(rhs.a - O);
		double C = d2.x * d2.x + d2.y * d2.y - R * R;
		double D = B * B -4 * A * C;
		if(cmp(D) >= 0){
			double t1 = (-B - sqrt(max(0.0, D))) / (2.0 * A);
			double t2 = (-B + sqrt(max(0.0, D))) / (2.0 * A);
			if(cmp(t1 - 1) <= 0 && cmp(t1) >= 0)
				res.push_back(rhs.a + d1 * t1);
			if(cmp(t1 - t2) != 0 && cmp(t2 - 1) <= 0 && cmp(t2) >= 0)
				res.push_back(rhs.a + d1 * t2);
		}
		return res;
	}
	/*
	 * the intersections of two circle
	 */
	pair<Point, Point> Intersection(const Circle &rhs) const {
		double d = (O - rhs.O).Abs();
		double cost = (R * R + d * d - rhs.R * rhs.R) / (2.0 * R * d);
		double sint = sqrt(1.0 - cost * cost);
		Point rfn = (rhs.O - O) / d * R;
		return {O + rfn.Rotate(cost, sint), O + rfn.Rotate(cost, -sint)};
	}
	friend ostream& operator << (ostream& out, const Circle &rhs){
		out << "C{" << rhs.O << ", " << rhs.R << "}";
		return out;
	}
	bool operator < (const Circle &rhs) const {
		if(cmp(R - rhs.R) != 0) return cmp(R - rhs.R) < 0;
		return O < rhs.O;
	}
	bool operator == (const Circle &rhs) const {
		return cmp(R - rhs.R) == 0 && O == rhs.O;
	}
};

/*
 * circumcircle of two points
 */
Circle Center(const Point &rhs1, const Point &rhs2){
	return Circle((rhs1+rhs2)/2.0, rhs1.Dist(rhs2)/2.0);
}
/*
 * circumcircle of three points
 */
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
typedef pair<int, int> PII;
vector<Point> point;
vector<Point> p[2];
bool flag;
int n;
double r;

bool check(){
    Circle c0, c1;
    if(p[0].size() != 0)
        c0 = MinCircleCover(p[0]);
    if(p[1].size() != 0)
        c1 = MinCircleCover(p[1]);
    return c0.R <= r && c1.R <= r;
}

void dfs(int x){
    if(x == n){
        flag = true;
        printf("yes\n");
        return;
    }
    p[0].push_back(point[x]);
    if(check())
        dfs(x+1);
    if(flag) return;
    p[0].pop_back();

    p[1].push_back(point[x]);
    if(check())
        dfs(x+1);
    if(flag) return;
    p[1].pop_back();
}


void Solve(){
    scanf("%d%lf", &n, &r);
    flag = false;
    point.clear();
    p[0].clear();
    p[1].clear();
    for(int i = 0 ; i < n ; i++){
        double x, y;
        scanf("%lf%lf", &x, &y);
        point.push_back({x, y});
    }
    dfs(0);
    if(!flag)
        printf("no\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
