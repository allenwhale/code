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
		return !cmp(x - rhs.x) && !cmp(y - rhs.y);
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
    Circle(){}
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
		return cmp(O.Dist(rhs) - R) <= 0;
	}
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
            res.push_back(rhs.a + d1 * t1);
            res.push_back(rhs.a + d1 * t2);
		}
		return res;
	}
	/*
	 * the intersections of two circle
	 */
	vector<Point> Intersection(const Circle &rhs) const {
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

Circle c[100];
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lf%lf%lf", &c[i].O.x, &c[i].O.y, &c[i].R);
    }
    double ans = 0;
    for(int i = 0 ; i < N ; i++){
        if(c[i].O == Point(0., 0.)){
            bool tf = true;
            for(int j = 0 ; j < N ; j++){
                if((c[i].O.Dist(c[j].O) + c[i].R - c[j].R) > 0)
                    tf = false;
            }
            if(tf)
                ans = max(ans, c[i].R);
        }else{
            auto res = c[i].Intersection(Line(Point(0., 0.), c[i].O));
            for(auto &x : res){
                bool tf = true;
                for(int k = 0 ; k < N ; k++){
                    if(c[k].InCircle(x) == false){
                        tf = false;
                        break;
                    }
                }
                if(tf){
                    ans = max(ans, x.Dist({0., 0.}));
                }
            }
        }
        for(int j = i + 1 ; j < N ; j++){
            if(cmp((c[i].R + c[j].R) - c[i].O.Dist(c[j].O)) >= 0){
                auto res = c[i].Intersection(c[j]);
                for(auto &x : res){
                    bool tf = true;
                    for(int k = 0 ; k < N ; k++){
                        if(c[k].InCircle(x) == false){
                            tf = false;
                            break;
                        }
                    }
                    if(tf){
                        ans = max(ans, x.Dist({0., 0.}));
                    }
                }
            }
        }
    }
    printf("%.3f\n", ans);
    return 0;
}
