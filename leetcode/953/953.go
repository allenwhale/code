package main

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func check(s1, s2 string, order map[byte]int) bool {
	for i := 0; i < min(len(s1), len(s2)); i++ {
		if order[s1[i]] > order[s2[i]] {
			return false
		} else if order[s1[i]] < order[s2[i]] {
			return true
		}
	}
	return len(s1) < len(s2)
}
func isAlienSorted(words []string, order string) bool {
	ord := make(map[byte]int)
	for i, c := range order {
		ord[byte(c)] = i
	}
	for i := 0; i < len(words)-1; i++ {
		if !check(words[i], words[i+1], ord) {
			return false
		}
	}
	return true
}
func main() {

}
