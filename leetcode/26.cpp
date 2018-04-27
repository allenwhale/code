#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.size() == 0)return 0;
            auto dst = nums.begin(), first = nums.begin(), last = nums.end();
            ++first;
            while(first != last){
                if(*dst != *first)
                    *(++dst) = *first;
                ++first;
            }
            return dst - nums.begin() + 1;
        }
};

int main(){
    return 0;
}
