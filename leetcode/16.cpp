#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int ans = nums[0] + nums[1] + nums[2];
            for(int i = 0 ; i < (int)nums.size() - 2 ; i++){
                int j = i + 1, k = nums.size() - 1;
                while(j < k){
                    int now = nums[i] + nums[j] + nums[k];
                    if(abs(now -target) < abs(ans - target))
                        ans = now;
                    if(now > target) k--;
                    else j++;
                }
            }
            return ans;
        }
};

int main(){
    Solution sol;
    vector<int> vc = {-1, 2, 1, -4};
    printf("%d\n", sol.threeSumClosest(vc, 1));
    return 0;
}
