#include <bits/stdc++.h>
using namespace std;
int count(const string &x){
    int cnt[26] = {0};
    for(char c : x){
        if(c == ' ')continue;
        cnt[c - 'A'] = 1;
    }
    int ans = 0;
    for(int i=0;i<26;i++)
        ans += cnt[i];
    return ans;
}
struct S{
    string s;
    int cnt;
    bool operator < (const S &x) const {
        if(cnt != x.cnt)
            return cnt > x.cnt;
        return s < x.s;
    }
}s[110];
void Solve(){
    int N;
    scanf("%d%*c", &N);
    string in;
    for(int i=0;i<N;i++){
        getline(cin, in);
        s[i].s = in;
        s[i].cnt = count(in);
    }
    sort(s, s + N);
    printf("%s\n", s[0].s.c_str());
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++){
        printf("Case #%d: ", i);
        Solve();
    }
    return 0;
}
