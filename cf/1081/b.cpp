#include <bits/stdc++.h>
using namespace std;

int N;
int a[100010], b[100010];
int main() {
    scanf("%d", &N);
    unordered_map<int, int> mp;
    unordered_map<int, int> ans_mp;
    unordered_map<int, int> ans_cnt;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        a[i] = N - a[i];
        mp[a[i]] += 1;
    }
    int ans = 0;
    bool possible = true;
    for (auto &p : mp) {
        int num = p.first, cnt = p.second;
        if (cnt % num != 0) {
            possible = false;
        }else{
            ans_mp[num] = ans;
            ans += cnt / num;
        }
    }
    if (possible && ans <= N) {
        printf("Possible\n");
        for (int i = 0; i < N; i++) {
            b[i] = ans_mp[a[i]];
            ans_cnt[a[i]]++;
            if (ans_cnt[a[i]] == a[i]) {
                ans_mp[a[i]]++;
                ans_cnt[a[i]] = 0;
            }
            printf("%d ", b[i] + 1);
        }
        printf("\n");
    }else{
        printf("Impossible\n");
    }
    return 0;
}
