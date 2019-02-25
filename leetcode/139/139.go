package main

import "fmt"

func wordBreak(s string, wordDict []string) bool {
	wordSet := map[string]bool{}
	for _, w := range wordDict {
		wordSet[w] = true
	}
	dp := make([]bool, len(s)+1)
	dp[0] = true
	for i := 0; i < len(s); i += 1 {
		for j := i + 1; j <= len(s); j += 1 {
			if wordSet[s[i:j]] {
				dp[j] = dp[j] || dp[i]
			}
		}
	}
	return dp[len(s)]
}
func main() {
	fmt.Println(wordBreak("leetcode", []string{"leet", "code"}))
	fmt.Println(wordBreak("applepenapple", []string{"apple", "pen"}))
	fmt.Println(wordBreak("catsandog", []string{"cats", "dog", "sand", "and", "cat"}))
}
