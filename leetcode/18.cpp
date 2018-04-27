#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        struct vc_hash{
            int operator () (const vector<int> &n) const {
                return n[0] ^ n[1] ^ n[2] ^ n[3];
            }
        };
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());
            unordered_set<vector<int>, vc_hash> st;
            for(int i = 0 ; i < (int)nums.size() - 3 ; i++){
                for(int j = i + 1 ; j < (int)nums.size() - 2 ; j++){
                    int k = j + 1, l = nums.size() - 1;
                    while(k < l){
                        int now = nums[i] + nums[j] + nums[k] + nums[l];
                        if(now == target){
                            st.insert({nums[i], nums[j], nums[k], nums[l]});
                        }
                        if(now < target){
                            k++;
                        }else l--;
                    }
                }
            }
            return vector<vector<int>>(st.begin(), st.end());
        }
};

int main(){
    return 0;
}
