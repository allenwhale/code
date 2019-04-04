package main

import "fmt"

func scoreOfParentheses(S string) int {
	ans, cnt := 0, -1
	for i, c := range S {
		if c == '(' {
			cnt++
		} else {
			if S[i-1] == '(' {
				ans = ans + 1<<uint(cnt)
			}
			cnt--
		}
	}
	return ans
}
func main() {
	fmt.Println(scoreOfParentheses("()"))
	fmt.Println(scoreOfParentheses("(())"))
	fmt.Println(scoreOfParentheses("()()"))
}
