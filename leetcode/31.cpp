#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int i = nums.size() - 1;
            while(i && nums[i - 1] >= nums[i])i--;
            if(i == 0){
                reverse(nums.begin(), nums.end());
                return;
            }
            swap(nums[i - 1], *upper_bound(nums.rbegin(), nums.rbegin() + nums.size() - i, nums[i - 1]));
            reverse(nums.begin() + i, nums.end());
        }
};

int main(){
    return 0;
}
