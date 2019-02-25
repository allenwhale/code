package main

import "fmt"
import "strings"
import "strconv"

func dfs(s []byte, tmp []string, ans *[]string) {
	if len(s) == 0 && len(tmp) == 4 {
		*ans = append(*ans, strings.Join(tmp, "."))
		return
	}
	if len(s) == 0 || len(tmp) == 4 {
		return
	}
	if s[0] == '0' {
		dfs(s[1:], append(tmp, "0"), ans)
	} else {
		for i := 1; i <= 3 && len(s) >= i; i += 1 {
			if x, _ := strconv.Atoi(string(s[:i])); x <= 255 {
				dfs(s[i:], append(tmp, string(s[:i])), ans)
			}
		}
	}
}

func restoreIpAddresses(s string) []string {
	ans := []string(nil)
	dfs([]byte(s), []string(nil), &ans)
	return ans
}

func main() {
	fmt.Println(restoreIpAddresses("25525511135"))
}
