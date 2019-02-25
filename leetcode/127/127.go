package main

import (
	"fmt"
)

func ladderLength(beginWord string, endWord string, wordList []string) int {
	vis := make(map[string]bool)
	for _, s := range wordList {
		vis[s] = true
	}
	if vis[endWord] == false {
		return 0
	}
	if beginWord == endWord {
		return 1
	}
	ans := 1
	src, dst := map[string]bool{beginWord: true}, map[string]bool{endWord: true}
	for len(src) > 0 && len(dst) > 0 {
		if len(src) > len(dst) {
			src, dst = dst, src
		}
		ndis := map[string]bool{}
		for s, _ := range src {
			for i := 0; i < 26; i += 1 {
				for j := 0; j < len(s); j += 1 {
					if byte(s[j]) == byte(i)+byte('a') {
						continue
					}
					ns := s[:j] + string(byte(i)+byte('a')) + s[j+1:]
					if dst[ns] {
						return ans + 1
					}
					if vis[ns] {
						delete(vis, ns)
						ndis[ns] = true
					}
				}
			}
		}
		src, ans = ndis, ans+1
	}
	return 0
}
func main() {
	fmt.Printf("test")
}
