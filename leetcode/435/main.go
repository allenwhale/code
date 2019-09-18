package main

import "sort"

func eraseOverlapIntervals(intervals [][]int) int {
	if len(intervals) == 0 {
		return 0
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][1] < intervals[j][1]
	})
	last, ans := 0, 0
	for i, v := range intervals[1:] {
		if (intervals[last][0] <= v[0] && v[0] < intervals[last][1]) || (v[0] < intervals[last][1] && intervals[last][1] <= v[1]) {
			ans++
		} else {
			last = i + 1
		}
	}
	return ans
}
func main() {

}
