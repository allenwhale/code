#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool isValid(string s) {
            stack<char> stk;
            for(char x : s){
                if(x == '(' || x == '[' || x == '{')
                    stk.push(x);
                else {
                    if(stk.empty())
                        return false;
                    if(x == ')' && stk.top() != '(')
                        return false;
                    if(x == ']' && stk.top() != '[')
                        return false;
                    if(x == '}' && stk.top() != '{')
                        return false;
                    stk.pop();
                }
            }
            return stk.empty();
		}
};

int main(){
    Solution sol;
    printf("%d\n", sol.isValid("()"));
	return 0;
}
