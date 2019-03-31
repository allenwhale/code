package main

import (
	"fmt"
	"math"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func isMax(a, b int) bool {
	return a > b
}
func isMin(a, b int) bool {
	return a < b
}

type Updater struct {
	n    int
	arr  []int
	comp func(int, int) bool
}

func NewUpdater(arr []int, comp func(int, int) bool) *Updater {
	return &Updater{
		n:    len(arr),
		arr:  append(arr, arr[0]),
		comp: comp,
	}
}
func (updater *Updater) update(x int) {
	updater.arr[updater.n] = x
	for i := updater.n; i > 0; i-- {
		if updater.comp(updater.arr[i], updater.arr[i-1]) {
			updater.arr[i], updater.arr[i-1] = updater.arr[i-1], updater.arr[i]
		} else {
			break
		}
	}
}
func maximumProduct(nums []int) int {
	mxUpdater := NewUpdater([]int{math.MinInt32, math.MinInt32, math.MinInt32}, isMax)
	mnUpdater := NewUpdater([]int{math.MaxInt32, math.MaxInt32}, isMin)
	for _, v := range nums {
		mxUpdater.update(v)
		mnUpdater.update(v)
	}
	return max(mxUpdater.arr[0]*mxUpdater.arr[1]*mxUpdater.arr[2],
		mnUpdater.arr[0]*mnUpdater.arr[1]*mxUpdater.arr[0])
}
func main() {
	fmt.Println(maximumProduct([]int{1, 2, 3}))
	fmt.Println(maximumProduct([]int{1, 2, 3, 4}))
	fmt.Println(maximumProduct([]int{1, -2, 3, 4}))
	fmt.Println(maximumProduct([]int{-1, -2, -3, -4}))
}
