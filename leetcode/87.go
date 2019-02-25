package main

import _ "github.com/kr/pretty"
import "fmt"

func isScramble(s1 string, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	l := len(s1)
	dp := make([][][]bool, l)
	for i := 0; i < l; i += 1 {
		dp[i] = make([][]bool, l)
		for j := 0; j < l; j += 1 {
			dp[i][j] = make([]bool, l+1)
		}
	}
	for i := 0; i < l; i += 1 {
		for j := 0; j < l; j += 1 {
			if s1[i] == s2[j] {
				dp[i][j][1] = true
			} else {
				dp[i][j][1] = false
			}
		}
	}
	for k := 2; k <= l; k += 1 {
		for i := 0; i < l-k+1; i += 1 {
			for j := 0; j < l-k+1; j += 1 {
				for m := 1; m < k; m += 1 {
					dp[i][j][k] = dp[i][j][k] ||
						(dp[i][j][m] && dp[i+m][j+m][k-m]) ||
						(dp[i][j+k-m][m] && dp[i+m][j][k-m])
				}
			}
		}
	}
	return dp[0][0][l]
}
func main() {
	fmt.Println(isScramble("abc", "bca"))
	// fmt.Println(isScramble("great", "rgeat"))
	// fmt.Println(isScramble("abcde", "caebd"))
}
