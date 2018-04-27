#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int sign = x < 0;
            x = abs(x);
            string s = to_string(x);
            ::reverse(s.begin(), s.end());
            long long ans = stoll(s);
            if((sign && ans > INT_MAX) || (!sign && ans > (long long)INT_MAX + 1)) return 0;
            return ans * (sign ? -1 : 1);
        }
};

int main(){
    Solution sol;
    printf("%d\n", sol.reverse(120));
    printf("%d\n", sol.reverse(-321));
    printf("%d\n", sol.reverse(2147483647));
}
