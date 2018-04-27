#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long sign = (dividend < 0) ^ (divisor < 0);
        long long ldividend = abs((long long)dividend), ldivisor = abs((long long)divisor);
        long long ans = 0;
        while(ldividend >= ldivisor){
            long long a = 1, b = ldivisor;
            while(ldividend >= (b << 1)){
                b <<= 1, a <<= 1;
            }
            ldividend -= b, ans += a;
        }
        ans = sign ? -ans : ans;
        if((long long)INT_MIN <= ans && ans <= (long long)INT_MAX)
            return ans;
        return INT_MAX;
    }
};

int main(){
    return 0;
}
