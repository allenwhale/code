#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
char s[25010];
unordered_map<char, int> mp;
int find(char x){
    if(mp.find(x) == mp.end())
        mp[x] = mp.size() - 1;
    return mp[x];
}
int last_ptr[100], cnt[100];
void Solve(){
    memset(last_ptr, 0, sizeof(last_ptr));
    memset(cnt, 0, sizeof(cnt));
    mp.clear();
    scanf("%d", &N);
    scanf("%s", s);
    ll before = 0;
    for(int i=0;i<N;i++){
        int x = find(s[i]);
        cnt[x]++;
        last_ptr[x] = max(last_ptr[x], i);
    }
    for(int i=0;i<(int)mp.size();i++)
        before += last_ptr[i] * cnt[i];
    last_ptr[0] = cnt[0] - 1;
    for(int i=1;i<(int)mp.size();i++)
        last_ptr[i] = last_ptr[i - 1] + cnt[i];
    ll after = 0;
    for(int i=0;i<(int)mp.size();i++)
        after += last_ptr[i] * cnt[i];
    printf("%I64d\n", 5ll * (before - after));
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
