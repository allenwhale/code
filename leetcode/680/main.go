package main

func check(s string, i, j int) bool {
	for i < j {
		if s[i] == s[j] {
			i, j = i+1, j-1
		} else {
			return false
		}
	}
	return true
}
func validPalindrome(s string) bool {
	i, j := 0, len(s)-1
	for i < j {
		if s[i] == s[j] {
			i, j = i+1, j-1
		} else {
			return check(s, i, j-1) || check(s, i+1, j)
		}
	}
	return true
}
func main() {

}
