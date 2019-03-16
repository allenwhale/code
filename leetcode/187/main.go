package main

import "fmt"

func findRepeatedDnaSequences(s string) []string {
	if len(s) < 10 {
		return []string{}
	}
	mp := make(map[string]int, len(s)-10)
	for i := 0; i < len(s)-10+1; i++ {
		mp[s[i:i+10]]++
	}
	ans := make([]string, 0)
	for k, v := range mp {
		if v > 1 {
			ans = append(ans, k)
		}
	}
	return ans
}
func main() {
	fmt.Println(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
}
