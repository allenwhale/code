package main

import "fmt"

type Trie struct {
	ch  [2]*Trie
	cnt int
}

func insert(root *Trie, s []int) int {
	for i := 1; i < len(s); i++ {
		var sel int
		if s[i] == s[i-1] {
			sel = 0
		} else {
			sel = 1
		}
		if root.ch[sel] == nil {
			root.ch[sel] = &Trie{}
		}
		root = root.ch[sel]
	}
	root.cnt++
	return root.cnt
}
func maxEqualRowsAfterFlips(matrix [][]int) int {
	root, ans := &Trie{}, 0
	for _, s := range matrix {
		cnt := insert(root, s)
		if cnt > ans {
			ans = cnt
		}
	}
	return ans
}
func main() {
	fmt.Println(maxEqualRowsAfterFlips([][]int{[]int{0, 1}, []int{1, 1}}))
	fmt.Println(maxEqualRowsAfterFlips([][]int{[]int{0, 1}, []int{1, 0}}))
}
