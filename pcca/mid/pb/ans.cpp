#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Node;
typedef pair<int, Node> Edge;
#define MAXM 1000000
#define MAXN 100000
#define f first
#define s second
#define e1 s.f
#define e2 s.s
#define w f
Edge e[MAXM+10];
namespace DS{
    int p[MAXN+10];
    void init(int n){
        for(int i=0;i<n;i++)
            p[i] = i;
    }
    int find(int x){
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int a, int b){
        p[find(a)] = find(b);
    }
};
int N, M;
int main(){
    scanf("%d%d", &N, &M);
    for(int i=0;i<M;i++)
        scanf("%d%d%d", &e[i].e1, &e[i].e2, &e[i].w);
    sort(e, e+M);
    DS::init(N);
    int ans = 0, cnt = 0;
    for(int i=0;i<M&&cnt<N-1;i++){
        if(DS::find(e[i].e1) != DS::find(e[i].e2)){
            ans += e[i].w;
            DS::merge(e[i].e1, e[i].e2);
            cnt++;
        }
    }
    printf("%d\n", cnt == N-1 ? ans : -1);
    return 0;
}
