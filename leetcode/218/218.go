package main

import (
	"container/heap"
	"sort"
)

type Stat struct {
	x, h, in int
}
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func getSkyline(buildings [][]int) [][]int {
	ans := [][]int{}
	high, mx := map[int]int{0: 1}, 0
	stat := []Stat{}
	pq := &IntHeap{}
	heap.Init(pq)
	for _, b := range buildings {
		stat = append(stat, Stat{x: b[0], h: b[2], in: 1}, Stat{x: b[1], h: b[2], in: -1})
	}
	sort.Slice(stat, func(i int, j int) bool {
		if stat[i].x == stat[j].x {
			return stat[i].in == 1
		}
		return stat[i].x < stat[j].x
	})
	for _, s := range stat {
		if s.in == 1 {
			high[s.x] = high[s.x] + 1
			if high[s.x] == 1 {
				heap.Push(pq, s.h)
			}
		} else {
			high[s.x] = high[s.x] - 1
			if high[s.x] == 0 {
			}
		}
	}
}

func main() {

}
