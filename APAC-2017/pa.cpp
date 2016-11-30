#include <bits/stdc++.h>
using namespace std;
char s[110];
int cnt[110];
int Solve(){
    int start, end;
    scanf("%s", s);
    int len = strlen(s);
    scanf("%d%d", &start, &end);
    start--;
    cnt[0] = s[0] == 'B' ? 1 : 0;
    for(int i=1;i<len;i++){
        cnt[i] = cnt[i-1] + (s[i] == 'B' ? 1 : 0);
    }
    int new_start = start % len != 0 ? start + len - (start % len) : start;
    int  new_end = end % len != 0 ? end - (end % len) : end;
    int ans = (new_end - new_start) / len * cnt[len - 1];
    for(int i=start;i<new_start;i++)
        ans += s[i % len] == 'B' ? 1 : 0;
    for(int i=new_end;i<end;i++)
        ans += s[i % len] == 'B' ? 1 : 0;
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: %d\n", t, Solve());
    }
    return 0;
}
