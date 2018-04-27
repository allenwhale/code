#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto dst = nums.begin(), first = nums.begin(); 
        while(first != nums.end()){
            if(*first != val)
                *(dst++) = *first;
            ++first;
        }
        return dst - nums.begin();
    }
};

int main(){
    return 0;
}
