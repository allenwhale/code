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
/*
 * default is counterclockwise
 */
struct Polygon{
#define COUNTERCLOCKWISE 1
#define CLOCKWISE       -1
    int N;
    vector<Point> s;
    vector<double> A;
    Polygon(int n=0): N(n) {}
    Polygon& add(const Point &n){
        s.push_back(n);
        return *this;
    }
    /*
     * counterclockwise or clockwise
     * defined as above
     */
    int Order(){
        int t = 0;
        for(int i=0;i<N&&t==0;i++){
            int a = i, b = (i + 1) % N, c = (i + 2) % N;
            t = cmp((s[b] - s[a]).Cross(s[c] - s[b]));
        }
        return t;
    }
    double Perimeter(){
        double res = 0;
        for(int i=0;i<N;i++)
            res += s[i].Dist(s[(i + 1) % N]);
        return res;
    }
    double Area(){
        double res = 0;
        for(int i=0;i<N;i++)
            res += s[i].Cross(s[(i + 1) % N]);
        return fabs(res / 2.0);
    }
    Polygon ConvexHull(){
        //it is clockwise
        Polygon res, that = *this;
        sort(that.s.begin(), that.s.end());
        that.s.erase(unique(that.s.begin(), that.s.end()), that.s.end());
        vector<Point> &w = res.s;
        for(int i=0;i<(int)that.s.size();i++){
            int sz;
            while((sz=w.size()), 
                    sz > 1 && cmp((w[sz - 1] - w[sz - 2]).Cross(that.s[i] - w[sz - 2])) <= 0)
                w.pop_back();
            w.push_back(that.s[i]);
        }
        int k = w.size();
        for(int i=(int)that.s.size()-2;i>=0;i--){
            int sz;
            while((sz=w.size()), 
                    sz > k && cmp((w[sz - 1] - w[sz - 2]).Cross(that.s[i] - w[sz - 2])) <= 0)
                w.pop_back();
            w.push_back(that.s[i]);
        }
        if((int)that.s.size() > 1) w.pop_back();
        res.N = w.size();
        //res.A = vector<double>(res.N);
        //for(int i=0;i<res.N;i++)
        //res.A[i] = (res.s[(i + 1) % res.N] - res.s[i]).Arg();
        return res;
    }
#define INSIDE  1
#define ONEDGE  2
#define OUTSIDE 0
    int OnPolygon(const Point &n){
        Point rfn = Point(-INF, n.y);
        Line l = Line(n, rfn);
        int cnt = 0;
        for(int i=0;i<N;i++){
            if(Line(s[i], s[(i + 1) % N]).OnSegment(n))
                return ONEDGE;
            if(cmp(s[i].y - s[(i + 1) % N].y) == 0)
                continue;
            if(l.OnSegment(s[i])){
                if(cmp(s[i].y - s[(i + 1) % N].y) >= 0)
                    cnt++;
            }else if(l.OnSegment(s[(i + 1) % N])){
                if(cmp(s[(i + 1) % N].y - s[i].y) >= 0)
                    cnt++;
            }else if(l.IsIntersect(Line(s[i], s[(i + 1) % N])))
                cnt++;
        }
        return (cnt & 1);
    }
    bool IsIntersect(const Line &rhs){
        int i = (upper_bound(A.begin(), A.end(), (rhs.b-rhs.a).Arg()) - A.begin()) % N;
        int j = (upper_bound(A.begin(), A.end(), (rhs.a-rhs.b).Arg()) - A.begin()) % N;
        if(cmp((rhs.b - rhs.a).Cross(s[i] - rhs.a) * (rhs.b - rhs.a).Cross(s[j] - rhs.a)) <= 0)
            return true;
        return false;
    }
    int OnConvex(const Point &rhs){
        Point rfn = (s[0]+s[N/3]+s[2*N/3]) / 3.0;
        int l = 0, r = N;
        while(l+1 < r){
            int mid = (l+r) / 2;
            if(cmp((s[l]-rfn).Cross(s[mid]-rfn)) > 0){
                if(cmp((s[l]-rfn).Cross(rhs-rfn)) >= 0 && cmp((s[mid]-rfn).Cross(rhs-rfn)) < 0)
                    r = mid;
                else l = mid;
            }else{
                if(cmp((s[l]-rfn).Cross(rhs-rfn)) < 0 && cmp((s[mid]-rfn).Cross(rhs-rfn)) >= 0)
                    l = mid;
                else r = mid;
            }
        }
        r %= N;
        int z = cmp((s[r]-rhs).Cross(s[l]-rhs));
        if(z == 0) return ONEDGE;
        else if(z == 1) return OUTSIDE;
        else return INSIDE;
    }
};
int main(){
    int N;
    scanf("%d", &N);
    Polygon s;
    for(int i=0;i<N;i++){
        double a, b;
        scanf("%lf%lf", &a, &b);
        s.add({a, b});
    }
    s = s.ConvexHull();
    int M;
    scanf("%d", &M);
    int cnt = 0;
    for(int i=0;i<M;i++){
        double a, b;
        scanf("%lf%lf", &a, &b);
        int res = s.OnConvex({a, b});
        if(res == INSIDE || res == ONEDGE){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
