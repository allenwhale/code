package main

import "fmt"
import "github.com/kr/pretty"

func isInterleave(s1 string, s2 string, s3 string) bool {
	l1, l2, l3 := len(s1), len(s2), len(s3)
	if l1+l2 != l3 {
		return false
	}
	dp := make([][]bool, l1+1)
	for i := 0; i <= l1; i += 1 {
		dp[i] = make([]bool, l2+1)
	}
	dp[0][0] = true
	for i := 0; i <= l1; i += 1 {
		for j := 0; j <= l2; j += 1 {
			if i == 0 && j == 0 {
				continue
			} else if i == 0 {
				dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1])
			} else if j == 0 {
				dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1])
			} else {
				dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1])
			}
		}
	}
	return dp[l1][l2]
}
func main() {
	fmt.Println(isInterleave("aabcc", "dbbca", "aadbbcbcac"))
	fmt.Println(isInterleave("aabcc", "dbbca", "aadbbcbcac"))
	fmt.Println(isInterleave("aabcc", "dbbca", "aadbbbaccc"))
}
