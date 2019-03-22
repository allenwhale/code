#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        multiset<long long> st;
        for (int i = 0; i < min(k, (int)nums.size()); i++)
        {
            auto it = st.lower_bound((long long)nums[i] - t);
            if (it != st.end() && *it <= (long long)nums[i] + t)
            {
                return true;
            }
            st.insert(nums[i]);
        }
        for (int i = k; i < (int)nums.size(); i++)
        {
            auto it = st.lower_bound((long long)nums[i] - t);
            if (it != st.end() && *it <= (long long)nums[i] + t)
            {
                return true;
            }
            st.insert(nums[i]);
            st.erase(nums[i - k]);
        }
        return false;
    }
};
int main()
{
    vector<int> vc = {1, 5, 9, 1, 5, 9};
    Solution sol;
    printf("%d\n", sol.containsNearbyAlmostDuplicate(vc, 2, 3));
    return 0;
}