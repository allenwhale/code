#include <bits/stdc++.h>
using namespace std;
class Solution {
struct Stat {
    int x, h, in;
};
public:
vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
    vector<pair<int, int> > ans;
    vector<Stat> stat;
    for (auto &b : buildings) {
        stat.push_back({ b[0], b[2], 1 });
        stat.push_back({ b[1], b[2], -1 });
    }
    sort(stat.begin(), stat.end(), [](const Stat &a, const Stat &b){
            if (a.x == b.x) {
                if (a.in == b.in) {
                    if (a.in == 1) {
                        return a.h > b.h;
                    }else {
                        return a.h < b.h;
                    }
                }
                return a.in == 1;
            }
            return a.x < b.x;
        });
    multiset<int> st;
    st.insert(0);
    int mx = 0;
    for (auto &s : stat) {
        if (s.in == 1) {
            st.insert(s.h);
        }else{
            st.erase(st.find(s.h));
        }
        if (*st.rbegin() != mx) {
            mx = *st.rbegin();
            ans.push_back({ s.x, mx });
        }
    }
    return ans;
}
};
int main(int argc, char const *argv[]) {
	//[[0,2,3],[2,5,3]]
    Solution sol;

    vector<vector<int> > s = {{ 0, 2, 3 }, { 2, 5, 3 } };

    auto ans = sol.getSkyline(s);

    for (auto x:ans) {
        printf("%d %d\n", x.first, x.second);
    }
    return 0;
}
