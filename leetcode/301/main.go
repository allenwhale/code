package main

import (
	"github.com/kr/pretty"
)

func dfs(s string, i, cnt, rm int, mn *int, bs []byte, ans *map[string]bool) {
	rrm := rm + len(s) - i
	if cnt < 0 || rm > *mn {
		return
	}
	if cnt == 0 && rrm <= *mn {
		if rrm < *mn {
			*ans, *mn = make(map[string]bool, 1), rrm
		}
		(*ans)[string(bs)] = true
	}
	if i >= len(s) {
		return
	}
	if s[i] == '(' {
		dfs(s, i+1, cnt+1, rm, mn, append(bs, '('), ans)
		dfs(s, i+1, cnt, rm+1, mn, bs, ans)
	} else if s[i] == ')' {
		dfs(s, i+1, cnt-1, rm, mn, append(bs, ')'), ans)
		dfs(s, i+1, cnt, rm+1, mn, bs, ans)
	} else {
		dfs(s, i+1, cnt, rm, mn, append(bs, s[i]), ans)
	}
}
func removeInvalidParentheses(s string) []string {
	if s == "" {
		return []string{""}
	}
	ans, mn := make(map[string]bool), len(s)+1
	dfs(s, 0, 0, 0, &mn, []byte{}, &ans)
	res := make([]string, 0, len(ans))
	for k := range ans {
		res = append(res, k)
	}
	return res
}
func main() {
	pretty.Println(removeInvalidParentheses("n"))
	// pretty.Println(removeInvalidParentheses("()())()"))
	// pretty.Println(removeInvalidParentheses("(a)())()"))
	// pretty.Println(removeInvalidParentheses(")("))
}
