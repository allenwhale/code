#include <bits/stdc++.h>
using namespace std;
void Solve(){
    int N;
    scanf("%d", &N);
    deque<int> dq;
    while(N)
        dq.push_front(N%3), N/= 3;
    printf("%d", dq[0]);
    for(int i=1;i<(int)dq.size();i++)
        printf(" %d", dq[i]);
    puts("");
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
