package main

import "sort"

func customSortString(S string, T string) string {
	S, T = T, S
	bS := []byte(S)
	pri := make(map[byte]int)
	for i, c := range T {
		pri[byte(c)] = i
	}
	sort.Slice(bS, func(i, j int) bool { return pri[bS[i]] < pri[bS[j]] })
	return string(bS)
}
func main() {

}
