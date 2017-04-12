#include <bits/stdc++.h>
using namespace std;

char s[510];
bool vis[26];
int main(){
    scanf("%s", s);
    bool ans = true;
    for(int i=0;s[i];i++){
        if(vis[s[i] - 'a'])continue;
        if(s[i] != 'a' && !vis[s[i] - 'a' - 1])ans = false;
        vis[s[i] - 'a'] = true;
    }
    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}
