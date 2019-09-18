#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> topKFrequent(const vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for (auto &x : nums)
            mp[x]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto &kv : mp) {
            pq.push({kv.second, kv.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans(k);
        for (int i = k - 1; i >= 0 && pq.size(); i--) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
int main() {
    Solution sol;
    for (auto &x : sol.topKFrequent({1, 1, 1, 2, 2, 3}, 2))
        printf("%d\n", x);
    return 0;
}