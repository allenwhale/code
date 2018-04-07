#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &a[i]);
    int gcd = a[0];
    for(int i = 0 ; i < N ; i++)
        gcd = __gcd(gcd, a[i]);
    unordered_set<int> all_st(a, a + N);
    if(all_st.find(gcd) == all_st.end())printf("-1\n");
    else{
        printf("%d\n", 2 * N + 1);
        for(int i = 0 ; i < N ; i++)
            printf("%d %d ", gcd, a[i]);
        printf("%d\n", gcd);
    }
    return 0;
}
