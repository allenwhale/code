package main

import "github.com/kr/pretty"
import "sort"

type Interval struct {
    Start int
    End   int
}

type IntervalSlice []Interval
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func (i IntervalSlice) Len() int {
    return len(i)
}

func (i IntervalSlice) Swap(a, b int) {
    i[a], i[b] = i[b], i[a]
}

func (i IntervalSlice) Less(a, b int) bool {
    if i[a].Start == i[b].Start {
        return i[a].End < i[b].End
    }
    return i[a].Start < i[b].Start
}

func inRange(a, b, c int) bool {
    return a <= b && b <= c
}

func merge(intervals []Interval) []Interval {
    ans := []Interval{}
    sort.Sort(IntervalSlice(intervals))
    for i := 0 ; i < len(intervals) ; i++ {
        if len(ans) == 0 {
            ans = append(ans, intervals[i])
        } else {
            if inRange(ans[len(ans) - 1].Start, intervals[i].Start, ans[len(ans) - 1].End) ||
            inRange(ans[len(ans) - 1].Start, intervals[i].End, ans[len(ans) - 1].End) {
                ans[len(ans) - 1].End = max(ans[len(ans) - 1].End, intervals[i].End)
            } else {
                ans = append(ans, intervals[i])
            }
        }
    }
    return ans
}

func main() {
    pretty.Println(merge([]Interval{
        {1, 10},
        {2, 5},
        {11, 12},
    }))
}
