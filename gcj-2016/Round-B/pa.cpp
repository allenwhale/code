#include <bits/stdc++.h>
using namespace std;
int s[10];
struct Q{
    int t, n;
    bool operator < (const Q &q) const {
        return n < q.n;
    }
};
bool beat(int a, int b){
    return a == (b + 1) % 3;
};
char CHAR[] = "PRS";

string foo(const string &s, int a, int b){
    if(a == b){
        string tmp = "";
        tmp += s[a];
        return tmp;
    }
    string sa = foo(s, a, (a+b)/2), sb = foo(s, (a+b)/2+1, b);
    return min(sa, sb) + max(sa, sb);
}

void Solve(){
    int N;
    scanf("%d", &N);
    scanf("%d%d%d", &s[1], &s[0], &s[2]);
    vector<string> fans;
    for(int l=0;l<3;l++){
        vector<int> n, o;
        o.push_back(l);
        for(int j=0;j<N;j++){
            for(int k=0;k<(1<<j);k++){
                int a = o[k], b=(o[k]+1)%3;
                if(!((N-j-1)&1)){
                    n.push_back(min(a, b));
                    n.push_back(max(a, b));
                }else{
                    n.push_back(max(a, b));
                    n.push_back(min(a, b));
                }
            }
            o = n;
            n.clear();
        }
        int cnt[3] = {0};
        for(int i=0;i<(1<<N);i++)
            cnt[o[i]]++;
        bool ans = true;
        for(int i=0;i<3;i++)
            if(cnt[i] != s[i])
                ans = false;
        if(ans == true){
            string tmp = "";
            for(int i=0;i<(1<<N);i++)
                tmp += CHAR[o[i]];
            fans.push_back(foo(tmp, 0, tmp.size()-1));
        }
    }
    if(fans.size() == 0) puts("IMPOSSIBLE");
    else{
        sort(fans.begin(), fans.end());
        printf("%s\n", fans[0].c_str());
    }
}
int main(){
    int T, t = 1;
    scanf("%d", &T);
    while(T--){
        printf("Case #%d: ", t++);
        Solve();
    }
    return 0;
}

