#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef vector<int>::iterator it;
public:
    int findKth(const it nums1, int len1, const it nums2, int len2, int k){
        if(len1 < len2)
            return findKth(nums2, len2, nums1, len1, k);
        if(len2 == 0)
            return *(nums1 + k - 1);
        if(k == 1)
            return min(*nums1, *nums2);
        int mid1 = min(k / 2, len1), mid2 = min(k / 2, len2);
        if(*(nums1 + mid1 - 1) < *(nums2 + mid2 - 1)){
            return findKth(nums1 + mid1, len1 - mid1, nums2, len2, k - mid1);
        }else{
            return findKth(nums1, len1, nums2 + mid2, len2 - mid2, k - mid2);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if((len1 + len2) & 1)
            return findKth(nums1.begin(), len1, nums2.begin(), len2, (len1 + len2 + 1) / 2);
        else
            return (double)(findKth(nums1.begin(), len1, nums2.begin(), len2, (len1 + len2) / 2)
                + findKth(nums1.begin(), len1, nums2.begin(), len2, (len1 + len2) / 2 + 1)) / 2.;

    }
};

int main(){
    Solution sol;
    vector<int> v1 = {1, 2}, v2 = {3, 4};
    printf("%f\n", sol.findMedianSortedArrays(v1, v2));

}
