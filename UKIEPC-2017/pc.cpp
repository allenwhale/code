#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int d[10];
int main(){
    m["red"] = 1;
    m["yellow"] = 2;
    m["green"] = 3;
    m["brown"] = 4;
    m["blue"] = 5;
    m["pink"] = 6;
    m["black"] = 7;
    int N;
    scanf("%d", &N);
    int mode = 0;
    int mx = 0;
    for(int i = 0 ; i < N ; i++){
        char ball[100];
        scanf("%s", ball);
        d[m[ball]]++;
        if(m[ball] != 1){
            mx = max(mx, m[ball]);
            mode = 1;
        }
    }
    if(mode == 0){
        printf("%d\n", 1);
    }else{
        int ans = 0;
        for(int i = 2 ; i <= 7 ; i++)
            if(d[i])
                ans += i;
        printf("%d\n", ans + d[1] * (mx + 1));
    }
    return 0;
}
