#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            if(nums.size() == 0) return {-1, -1};
            auto first = lower_bound(nums.begin(), nums.end(), target);
            if(first == nums.end() || *first != target) return {-1, -1};
            auto end = upper_bound(nums.begin(), nums.end(), target);
            return {int(first - nums.begin()), int(end - nums.begin() - 1)};
        }
};
int main(){
    return 0;
}
