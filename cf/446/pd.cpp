#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
PII a[50];
bool cmp(const PII &a, const PII &b){
    return a.second < b.second;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + N);
    int tmp = a[0].first;
    for(int i = 0 ; i < N - 1; i++)
        a[i].first = a[i + 1].first;
    a[N - 1].first = tmp;
    sort(a, a + N, cmp);
    for(int i = 0 ; i < N ; i++)
        printf("%d ", a[i].first);
    puts("");
    return 0;
}
