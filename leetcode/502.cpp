#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaximizedCapital(int k, int W, vector<int> &Profits,
                             vector<int> &Capital) {
        vector<pair<int, int>> CP(Profits.size());
        for (int i = 0; i < (int)Profits.size(); i++) {
            CP[i] = {Capital[i], Profits[i]};
        }
        sort(CP.begin(), CP.end());
        priority_queue<int> pq;
        int idx = 0;
        for (int i = 0; i < k; i++) {
            while (idx < (int)CP.size() && CP[idx].first <= W) {
                pq.push(CP[idx].second);
                idx++;
            }
            if (pq.empty())
                break;
            W += pq.top();
            pq.pop();
        }
        return W;
    }
};

int main() {}