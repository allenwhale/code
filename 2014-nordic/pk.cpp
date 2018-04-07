#include <bits/stdc++.h>
using namespace std;

int main(){
    int C, N;
    scanf("%d%d", &C, &N);
    int now = 0;
    bool fail = false;
    for(int i = 0 ; i < N ; i++){
        int l, e, w;
        scanf("%d%d%d", &l, &e, &w);
        now -= l;
        if(now < 0)fail = true;
        now += e;
        if(now > C)fail = true;
        if(w && now != C)fail = true;
    }
    if(now) fail = true;
    if(fail)printf("impossible\n");
    else printf("possible\n");
    return 0;
}
