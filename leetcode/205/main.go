package main

import "fmt"

func isIsomorphic(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	mp := make(map[byte]byte, len(s))
	vis := make(map[byte]bool, len(s))
	for i := 0; i < len(s); i++ {
		v, ok := mp[s[i]]
		if ok {
			if v != t[i] {
				return false
			}
		} else {
			if _, ok := vis[t[i]]; ok {
				return false
			}
			mp[s[i]] = t[i]
			vis[t[i]] = true
		}
	}
	return true
}
func main() {
	fmt.Println(isIsomorphic("egg", "add"))
	fmt.Println(isIsomorphic("foo", "bar"))
	fmt.Println(isIsomorphic("paper", "title"))
	fmt.Println(isIsomorphic("ab", "aa"))
}
