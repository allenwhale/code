package main

import "fmt"

/*
 * @lc app=leetcode id=212 lang=golang
 *
 * [212] Word Search II
 */
type Trie struct {
	ch     [26]*Trie
	exists int
}

func buildTrie(words []string) *Trie {
	root := &Trie{exists: -1}
	for id, w := range words {
		tr := root
		for _, r := range w {
			c := int(byte(r) - byte('a'))
			if tr.ch[c] == nil {
				tr.ch[c] = &Trie{exists: -1}
			}
			tr = tr.ch[c]
		}
		tr.exists = id
	}
	return root
}

func search(tr *Trie, i, j int, board [][]byte, ans map[int]bool) {
	c := int(board[i][j] - byte('a'))
	if board[i][j] == ' ' || tr.ch[c] == nil {
		return
	}
	if tr.ch[c].exists != -1 {
		ans[tr.ch[c].exists] = true
	}
	o := board[i][j]
	board[i][j] = ' '
	if i != 0 {
		search(tr.ch[c], i-1, j, board, ans)
	}
	if i != len(board)-1 {
		search(tr.ch[c], i+1, j, board, ans)
	}
	if j != 0 {
		search(tr.ch[c], i, j-1, board, ans)
	}
	if j != len(board[0])-1 {
		search(tr.ch[c], i, j+1, board, ans)
	}
	board[i][j] = o
}

func findWords(board [][]byte, words []string) []string {
	if len(words) == 0 {
		return []string{}
	}
	R, C := len(board), len(board[0])
	root := buildTrie(words)
	ids := make(map[int]bool)
	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			search(root, i, j, board, ids)
		}
	}
	ans := []string{}
	for id := range ids {
		ans = append(ans, words[id])
	}
	return ans
}

func main() {
	fmt.Println(findWords([][]byte{[]byte{'a'}}, []string{"ab"}))
}
