#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            auto cmp = [&](int a, int b){
                if(a < nums[0] && nums[0] <= b)
                    return false;
                else if(b < nums[0] && nums[0] <= a)
                    return true;
                return a < b;
            };
            auto it = lower_bound(nums.begin(), nums.end(), target, cmp);
            return it != nums.end() && *it == target ? it - nums.begin() : -1;
        }
};

int main(){
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    nums = {1, 2, 3, 4, 5};
    int target = 4;
    printf("%d\n", sol.search(nums, target));
    return 0;
}
