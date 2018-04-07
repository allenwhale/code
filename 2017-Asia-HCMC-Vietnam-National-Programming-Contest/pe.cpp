#include <bits/stdc++.h>
using namespace std;
struct Point{
    double x, y;
    double norm2() const {
        return sqrt(x * x + y * y);
    }
    Point operator - (const Point &n) const {
        return {x - n.x, y - n.y};
    }
    Point operator + (const Point &n) const {
        return {x + n.x, y + n.y};
    }
    Point operator / (double d) const {
        return {x / d, y / d};
    }

}p[10];
int main(){
    int N = 3;
    Point ans;
    ans.x = ans.y = 0;
    for(int i = 0 ; i < N ; i++){
        scanf("%lf%lf", &p[i].x, &p[i].y);
        ans.x += p[i].x;
        ans.y += p[i].y;
    }
    ans.x /= (double)N;
    ans.y /= (double)N;
    Point delta;
    do{
        Point new_ans;
        new_ans.x = new_ans.y = 0;
        double norm = 0;
        for(int i = 0 ; i < N ; i++){
            double len = (ans - p[i]).norm2();
            if(abs(len) <= 1e-9){
                norm = 1;
                new_ans = p[i];
                break;
            }
            norm += 1.0 / len;
            new_ans = new_ans + p[i] / len;
        }
        new_ans = new_ans / norm;
        delta = new_ans - ans;
        ans = new_ans;
    }while(delta.norm2() > 1e-9);
    printf("%.15f %.15f\n", ans.x, ans.y);
    return 0;
}
