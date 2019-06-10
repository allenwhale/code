package main

import (
	"container/heap"

	"github.com/kr/pretty"
)

type State struct {
	s   string
	cnt int
}

type StateHeap []*State

func (h StateHeap) Len() int {
	return len(h)
}
func (h StateHeap) Less(i, j int) bool {
	if h[i].cnt == h[j].cnt {
		return h[i].s < h[j].s
	}
	return h[i].cnt > h[j].cnt
}
func (h StateHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}
func (h *StateHeap) Pop() interface{} {
	x := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return x
}
func (h *StateHeap) Push(x interface{}) {
	*h = append(*h, x.(*State))
}

func topKFrequent(words []string, k int) []string {
	cnt := make(map[string]int)
	for _, w := range words {
		cnt[w]++
	}
	h := &StateHeap{}
	for x := range cnt {
		*h = append(*h, &State{s: x, cnt: cnt[x]})
	}
	heap.Init(h)
	res := make([]string, 0, k)
	for i := 0; i < k; i++ {
		res = append(res, heap.Pop(h).(*State).s)
	}
	return res
}
func main() {
	pretty.Println(topKFrequent([]string{"i", "love", "leetcode", "i", "love", "coding"}, 2))
	pretty.Println(topKFrequent([]string{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4))
}
