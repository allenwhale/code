#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
  public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int n;
    MedianFinder() { n = 0; }

    void addNum(int num) {
        n++;
        pq2.push(num);
        pq1.push(pq2.top());
        pq2.pop();
        if (pq1.size() > pq2.size() + 1) {
            pq2.push(pq1.top());
            pq1.pop();
        }
    }

    double findMedian() {
        if (n & 1) {
            return pq1.top();
        } else {
            return (double)(pq1.top() + pq2.top()) / 2.;
        }
    }
};
int main() {
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    m.addNum(3);
    printf("%f\n", m.findMedian());
    return 0;
}