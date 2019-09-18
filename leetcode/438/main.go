package main

import "fmt"

func findAnagrams(s string, p string) []int {
	if len(s) < len(p) {
		return []int{}
	}
	cnt := make([]int, 26)
	for _, c := range p {
		cnt[byte(c)-byte('a')]++
	}
	i, same, ans := 0, 0, []int{}
	for ; i < len(p); i++ {
		cnt[s[i]-byte('a')]--
	}
	for c := 0; c < 26; c++ {
		if cnt[c] == 0 {
			same++
		}
	}
	if same == 26 {
		ans = append(ans, 0)
	}
	for ; i < len(s); i++ {
		c := s[i] - byte('a')
		cnt[c]--
		if cnt[c] == 0 {
			same++
		} else if cnt[c] == -1 {
			same--
		}
		c = s[i-len(p)] - byte('a')
		cnt[c]++
		if cnt[c] == 0 {
			same++
		} else if cnt[c] == 1 {
			same--
		}
		if same == 26 {
			ans = append(ans, i-len(p)+1)
		}
	}
	return ans
}

func main() {
	// fmt.Println(findAnagrams("cbaebabacd", "abc"))
	// fmt.Println(findAnagrams("abab", "ab"))
	fmt.Println(findAnagrams("bpaa", "aa"))
}
