package main

import (
	"github.com/kr/pretty"
)

type Node struct {
	s    string
	step int
}

type StringSet map[string]struct{}

func (set StringSet) Add(s ...string) {
	for _, v := range s {
		set[v] = struct{}{}
	}
}

func (set StringSet) Contain(s string) bool {
	_, ok := set[s]
	if ok {
		return true
	}
	return false
}

func genPaths(begin, end string, paths map[string]StringSet, path []string, ans *[][]string) {
	if end == begin {
		*ans = append(*ans, append([]string(nil), path...))
		return
	}
	for k, _ := range paths[end] {
		genPaths(begin, k, paths, append([]string{k}, path...), ans)
	}
}

func findLadders(beginWord string, endWord string, wordList []string) [][]string {
	queue := []Node{{beginWord, 0}}
	//queue := []string{}
	paths := map[string]StringSet{}
	visit := StringSet{}
	visit.Add(beginWord)
	depth := map[string]int{}
	wordSet := StringSet{}
	wordSet.Add(wordList...)
	for len(queue) != 0 {
		nowSS, nowS, nowStep := queue[0].s, []byte(queue[0].s), queue[0].step
		queue = queue[1:]
		for idx, v := range nowS {
			for i := 0; i < 26; i++ {
				if i != int(v-'a') {
					nowS[idx] = byte(i + int('a'))
					nextS := string(nowS)
					if wordSet.Contain(nextS) {
						if _, ok := depth[nextS]; !ok {
							depth[nextS] = nowStep + 1
							paths[nextS] = StringSet{}
							queue = append(queue, Node{nextS, nowStep + 1})
						}
						if depth[nextS] == nowStep+1 {
							paths[nextS].Add(nowSS)
						}
					}
					nowS[idx] = v
				}
			}
		}
	}
	ans := [][]string{}
	path := []string{endWord}
	genPaths(beginWord, endWord, paths, path, &ans)
	return ans
}
func main() {
	pretty.Println(findLadders("hit", "cog", []string{"hot", "dot", "dog", "lot", "log", "cog"}))
	pretty.Println(findLadders("hit", "cog", []string{"hot", "dot", "dog", "lot", "log"}))
}
