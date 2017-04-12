#include <bits/stdc++.h>
using namespace std;
int p[1000010];
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &p[i]);
    int T;
    scanf("%d", &T);
    while(T--){
        int q;
        scanf("%d", &q);
        p[q - 1] = -p[q - 1];
    }
    vector<int> stk;
    for(int i=N-1;i>=0;i--){
        if(p[i] < 0)
            stk.push_back(p[i]);
        else{
            if(stk.size() && p[i] == -stk.back())
                stk.pop_back();
            else{
                p[i] = -p[i];
                stk.push_back(p[i]);
            }
        }
    }
    if(stk.size())puts("NO");
    else{
        puts("YES");
        for(int i=0;i<N;i++)
            printf("%d ", p[i]);
        puts("");
    }
    return 0;
}
