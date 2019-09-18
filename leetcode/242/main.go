package main

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	cnt := [26]int{}
	for _, c := range s {
		cnt[byte(c)-'a']++
	}
	for _, c := range t {
		cnt[byte(c)-'a']--
	}
	for i := 0; i < 26; i++ {
		if cnt[i] != 0 {
			return false
		}
	}
	return true
}
func main() {

}
