#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        const char *ptr = str.c_str();
        while(isspace(*ptr))
            ++ptr;
        int sign = 1;
        if(*ptr == '-')
            sign = -1, ++ptr;
        else if(*ptr == '+')
            ++ptr;
        if(!isdigit(*ptr))return 0;
        long long res = 0;
        while(isdigit(*ptr)){
            res = res * 10 + *(ptr++) - '0';
            if(res > (long long)INT_MAX + 1)
                break;
        }
        if(sign == -1 && res > (long long)INT_MAX + 1)
            return INT_MIN;
        if(sign == 1 && res > (long long)INT_MAX)
            return INT_MAX;
        return res * sign;
    }
};

int main(){
    Solution sol;
    printf("%d\n", sol.myAtoi("123"));
    printf("%d\n", sol.myAtoi("-123"));
    printf("%d\n", sol.myAtoi("+123"));
    printf("%d\n", sol.myAtoi("-!123"));
    printf("%d\n", sol.myAtoi(""));
    printf("%d\n", sol.myAtoi("2147483648"));
    printf("%d\n", sol.myAtoi("-2147483649"));
    return 0;
}
