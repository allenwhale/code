#include <bits/stdc++.h>
using namespace std;

int p[1000010 * 3];
int main(){
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
        p[i] = i;
    int base = 0;
    for(int i=2;i<=N;i++,base++){
        for(int j=((N+i-1)/i-1)*i+1;j>0;j-=i){
            p[base + (j + i - 1 > N ? N + 1: j + i)] = p[base + j];
        }
    }
    for(int i=1;i<=N;i++)
        printf("%d ", p[base + i]);
    puts("");
    return 0;
}
