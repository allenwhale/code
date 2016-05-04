#include <bits/stdc++.h>
using namespace std;
char s[2][10];
int len[2];
vector<string> ans;
void Find(int x1, int x2, string now){
    if(x1 == len[0] && x2 == len[1]){
        ans.push_back(now);
        return;
    }
    if(x1 < len[0]){
        Find(x1 + 1, x2, now + s[0][x1]);
    }
    if(x2 < len[1]){
        Find(x1, x2 + 1, now + s[1][x2]);
    }
}
void Solve(){
    ans.clear();
    scanf("%s%s", s[0], s[1]);
    len[0] = strlen(s[0]);
    len[1] = strlen(s[1]);
    Find(0, 0, "");
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    for(string& x: ans)
        printf("%s\n", x.c_str());
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        Solve();
        puts("");
    }
    return 0;
}
