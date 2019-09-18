#include <bits/stdc++.h>
using namespace std;
class KthLargest {
  public:
    KthLargest(int k, const vector<int> &nums) : K(k) {
        for (auto &x : nums)
            add(x);
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > K)
            pq.pop();
        return pq.top();
    }

  private:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
};

int main() {}