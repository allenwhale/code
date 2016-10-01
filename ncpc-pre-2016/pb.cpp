#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;
#define f first
#define s second
int main(){
    int N, M, P;
    while(~scanf("%d%d%d", &N, &M, &P)&&N&&M&&P){
        vector<PI> vc;
        for(int i=0;i<P;i++){
            int x, y;
            scanf("%d%d", &x, &y);
            vc.push_back(make_pair(x, y));
        }
        sort(vc.begin(), vc.end());
        for(int i=0;i<(int)vc.size();i++)
            vc[i].s = -vc[i].s;
        vector<int> lis;
        lis.push_back(vc[0].s);
        for(int i=1;i<(int)vc.size();i++){
            if(vc[i].s > lis.back())
                lis.push_back(vc[i].s);
            else{
                *lower_bound(lis.begin(), lis.end(), vc[i].s) = vc[i].s;
            }
        }
        printf("%d\n", (int)lis.size());
    }
    return 0;
}
