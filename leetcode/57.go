package main

import "github.com/kr/pretty"
type Interval struct {
    Start int
    End   int
}
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func overlap(a, b Interval) Interval {
    return Interval{min(a.Start, b.Start), max(a.End, b.End)}
}
func insert(intervals []Interval, newInterval Interval) []Interval {
    if len(intervals) == 0 {
        return []Interval{newInterval}
    }
    ans, i := []Interval{}, 0
    for i < len(intervals) && intervals[i].End < newInterval.Start {
        ans, i = append(ans, intervals[i]), i + 1
    }
    for i < len(intervals) && newInterval.End >= intervals[i].Start{
        newInterval, i = overlap(newInterval, intervals[i]), i + 1
    }
    ans = append(ans, newInterval)
    ans = append(ans, intervals[i : len(intervals)]...)
    return ans
}
func main() {
    pretty.Println(insert([]Interval{{1, 3}, {6, 9}}, Interval{2, 5}))
}
