package main

import "sort"

func isMonotonic(A []int) bool {
	if sort.IsSorted(sort.IntSlice(A)) {
		return true
	}
	if sort.IsSorted(sort.Reverse(sort.IntSlice(A))) {
		return true
	}
	return false
}
func main() {

}
