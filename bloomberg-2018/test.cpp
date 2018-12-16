//Problem        : Ergonomics
//Language       : C++11
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include <string.h>
#include <map>

using namespace std;
int R, C;
char mp[1000][1000], in[1000];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int dis[1000][1000];
bool isin(int x, int y){

    return x >= 0 && y >= 0 && x < R && y < C;
}
int main() {
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++)
        scanf("%s", mp[i]);
    fgets(in, 1000, stdin);
    fgets(in, 1000, stdin);
    int H = 0;
    queue<pair<int, int> > q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mp[i][j] == 'H') {
                H++;
                q.push({ i, j });
                dis[i][j] = 0;
            }
        }
    }
    vector<int> s;
    while (!q.empty()) {
        auto n = q.front();
        q.pop();
        if (mp[n.first][n.second] == 'O' || mp[n.first][n.second] == 'H')
            s.push_back(dis[n.first][n.second]);
        for (int i = 0; i < 4; i++) {
            int tx = n.first + dx[i], ty = n.second + dy[i];
            if (isin(tx, ty) && dis[tx][ty] > dis[n.first][n.second] + 1) {
                dis[tx][ty] = dis[n.first][n.second] + 1;
                q.push({ tx, ty });
            }
        }
    }
    int len = strlen(in);
    map<char, int>mp;
    for (int i = 0; i < len; i++) {
        if ('a' <= in[i] && in[i] <= 'z') {
            mp[in[i]]++;
        }
    }
    vector<int> vc;
    for (auto x:mp)
        vc.push_back(x.second);
    sort(s.begin(), s.end());
    sort(vc.begin(), vc.end());
    reverse(vc.begin(), vc.end());
	// for (auto x: st)
	//     printf("%c", x);
	// puts("");
	// printf("%d\n", st.size());
	// for (int i = 0; i < s.size(); i++)
	//     printf("%d\n", s[i]);
    int ans = 0;
    for (int i = 0; i < vc.size(); i++)
        ans += s[i] * vc[i];
    printf("%d\n", ans);

    return 0;
}
