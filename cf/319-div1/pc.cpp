#include <bits/stdc++.h>
using namespace std;
struct point{
    int id;
    long long x,y;
    int block;
};
#define dist(a,b) (abs(a.x-b.x)+abs(a.y-b.y))
bool cmp(point a, point b){
    if(a.block==b.block)
        if(a.block&1){
            return a.y<b.y;
        }else{
            return a.y>b.y;
        }
    return a.block<b.block;
}
point p[1000010];
int main(){
    srand(time(0));
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        p[i].id=i;
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
        p[i].block=p[i].x/1000;
    }
    sort(p+1,p+1+N,cmp);
    for(int i=1;i<=N;i++)
        printf("%d%c",p[i].id,(i==N)?'\n':' ');
    return 0;
}
