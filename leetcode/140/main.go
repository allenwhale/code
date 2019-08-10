package main

import (
	"github.com/kr/pretty"
)

func check(s string, wordSet map[string]bool) bool {
	dp := make([]bool, len(s)+1)
	dp[len(s)] = true
	for i := len(s) - 1; i >= 0; i-- {
		for j := i; j <= len(s) && !dp[i]; j++ {
			if wordSet[s[i:j]] {
				dp[i] = dp[i] || dp[j]
			}
		}
	}
	return dp[0]
}

func wordBreak(s string, wordDict []string) []string {
	wordSet := make(map[string]bool, len(wordDict))
	for _, s := range wordDict {
		wordSet[s] = true
	}
	if !check(s, wordSet) {
		return []string{}
	}
	ans := make([][]string, len(s)+1)
	ans[len(s)] = []string{""}
	for i := len(s) - 1; i >= 0; i-- {
		ans[i] = []string{}
		for j := i; j <= len(s); j++ {
			if wordSet[s[i:j]] {
				if j == len(s) {
					ans[i] = append(ans[i], s[i:j])
				} else {
					for _, w := range ans[j] {
						ans[i] = append(ans[i], s[i:j]+" "+w)
					}
				}
			}
		}
	}
	return ans[0]
}
func main() {
	pretty.Println(wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", []string{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"}))
	pretty.Println(wordBreak("catsanddog", []string{"cat", "cats", "and", "sand", "dog"}))
	pretty.Println(wordBreak("pineapplepenapple", []string{"apple", "pen", "applepen", "pine", "pineapple"}))
}
