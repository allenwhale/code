package main

import "fmt"

type trie struct {
	ch  [26]*trie
	end bool
}

func insert(tr *trie, word string) {
	for _, x := range word {
		if tr.ch[int(x-'a')] == nil {
			tr.ch[int(x-'a')] = &trie{}
		}
		tr = tr.ch[int(x-'a')]
	}
	tr.end = true
}

func buildTrie(words []string) *trie {
	root := &trie{}
	for _, word := range words {
		insert(root, word)
	}
	return root
}

func search(tr *trie, idx int, s string, cnt int) bool {
	root := tr
	// fmt.Println(s, idx, cnt)
	for i := idx; i < len(s); i++ {
		if tr.ch[int(s[i]-'a')] != nil {
			tr = tr.ch[int(s[i]-'a')]
			if i == len(s)-1 {
				return tr.end && cnt >= 1
			} else {
				if tr.end && search(root, i+1, s, cnt+1) {
					return true
				}

			}
		} else {
			return false
		}
	}
	return false
}

func findAllConcatenatedWordsInADict(words []string) []string {
	root := buildTrie(words)
	ans := make([]string, 0)
	for _, s := range words {
		if search(root, 0, s, 0) {
			ans = append(ans, s)
		}
	}
	return ans
}
func main() {
	// ws := []string{"rfkqyuqfjkx", "", "vnrtysfrzrmzl", "gfve", "qfpd"}
	ws := []string{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"}
	fmt.Println(findAllConcatenatedWordsInADict(ws))
}
