#include <bits/stdc++.h>
using namespace std;
#define min(a, b, c) (min((a), min((b), (c))))
#define max(a, b, c) (max((a), max((b), (c))))
class Solution {
    struct vc_hash{
        int operator () (const vector<int>& x) const {
            int res = 0;
            for(int y : x) res ^= y;
            return res;
        }
    };
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            unordered_set<vector<int>, vc_hash> st;
            unordered_set<int> vis;
            for(int i = 0 ; i < (int)nums.size() ; i++){
                for(int j = i + 1 ; j < (int)nums.size() ; j++){
                    if(vis.find(-nums[i] - nums[j]) != vis.end()){
                        int a = min(nums[i], nums[j], -nums[i] - nums[j]), b = max(nums[i], nums[j], -nums[i] - nums[j]);
                        st.insert({a, -a - b, b});
                    }
                }
                vis.insert(nums[i]);
            }
            return vector<vector<int>>(st.begin(), st.end());
        }
};

int main(){
    Solution sol;
    vector<int> in = {-1,0,1,2,-1,-4};
    auto ans = sol.threeSum(in);
    for(auto &x : ans){
        for(auto &y : x)
            printf("%d ", y);
        puts("");
    }
    return 0;
}
