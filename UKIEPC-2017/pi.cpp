#include <bits/stdc++.h>
using namespace std;
int a[20];
int main(){
    int N, T;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &T);
    int mn = INT_MAX, ans;
    for(int i = 0 ; i < N ; i++){
        if(mn > T % a[i]){
            mn = T % a[i];
            ans = a[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
