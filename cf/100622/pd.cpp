#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("dragon.in", "r", stdin);
    freopen("dragon.out", "w", stdout);
    int N, D;
    scanf("%d%d", &N, &D);
    if((int)to_string(D).size() <= N){
        printf("%d", D);
        for(int i=0;i<N-(int)to_string(D).size();i++)
            printf("0");
        printf("\n");
    }else printf("No solution\n");
    
   
    return 0;
}
