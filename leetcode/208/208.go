package main

type TrieNode struct {
	ch   [26]*TrieNode
	leaf bool
}
type Trie struct {
	root *TrieNode
}

/** Initialize your data structure here. */
func Constructor() Trie {
	res := Trie{
		root: &TrieNode{},
	}
	return res
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	cur := this.root
	for _, s := range word {
		idx := byte(s) - byte('a')
		if cur.ch[idx] == nil {
			cur.ch[idx] = &TrieNode{}
		}
		cur = cur.ch[idx]
	}
	cur.leaf = true
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	cur := this.root
	for _, s := range word {
		idx := byte(s) - byte('a')
		if cur.ch[idx] == nil {
			return false
		}
		cur = cur.ch[idx]
	}
	return cur.leaf
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	cur := this.root
	for _, s := range prefix {
		idx := byte(s) - byte('a')
		if cur.ch[idx] == nil {
			return false
		}
		cur = cur.ch[idx]
	}
	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
func main() {

}
