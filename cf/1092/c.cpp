#include <bits/stdc++.h>
using namespace std;
char in[110];
vector<string> s[110];
set<int> available[110][2];
vector<int> id[110];
int ans[110 * 2];
int N;
bool startswith(const string &a, const string &b){
    for (int i = 0; i < (int)b.length(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
bool endswith(const string &a, const string &b){
    for (int i = 0; i < (int)b.length(); i++) {
        if (a[i + a.length() - b.length()] != b[i]) {
            return false;
        }
    }
    return true;
}
bool check(const string &x){
	// printf("chk %s\n", x.c_str());

    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < 2; j++) {
            available[i][j].clear();
            if (startswith(x, s[i][j])) {
                available[i][j].insert(0);
            }
            if (endswith(x, s[i][j])) {
                available[i][j].insert(1);
            }
        }
        if (available[i][0].count(0) && available[i][1].count(1)) {
            ans[id[i][0]] = 0;
            ans[id[i][1]] = 1;
        } else if (available[i][0].count(1) && available[i][1].count(0)) {
            ans[id[i][0]] = 1;
            ans[id[i][1]] = 0;
        }else{
			// printf("err %d\n", i);
            return false;
        }
    }
    return true;
}
int main(){

    scanf("%d", &N);
    for (int i = 0; i < 2 * N - 2; i++) {
        scanf("%s", in);
        int len = strlen(in);
        s[len].push_back(in);
        id[len].push_back(i);
    }
    bool tf;
    if (!(tf = check(s[N - 1][0] + s[N - 1][1].back()))) {
        tf = check(s[N - 1][1] + s[N - 1][0].back());
    }
	// printf("%d\n", tf);
    for (int i = 0; i < 2 * N - 2; i++) {
        printf("%c", ans[i] ? 'S' : 'P');
    }
    printf("\n");

    return 0;
}
