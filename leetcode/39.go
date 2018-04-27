package main

import "fmt"

import "sort"

func unique(s []int) []int {
    dst, first := 0, 1
    for ; first < len(s) ; first++ {
        if(s[dst] != s[first]) {
            s[dst + 1], dst = s[first], dst + 1
        }
    }
    return s[: dst + 1]
}

func dfs(candidates []int, target int, now []int, ans *[][]int) {
    //fmt.Println(now, target)
    if target == 0 {
        newNow := make([]int, len(now))
        copy(newNow, now)
        *ans = append(*ans, newNow)
        return
    }
    if len(candidates) == 0 {
        return
    }
    var i int
    for i = 0 ; target >= candidates[0] * i ; i++ {
        dfs(candidates[1 :], target - candidates[0] * i, now, ans)
        now = append(now, candidates[0])
    }
    now = now[: len(now) - i]
}

func combinationSum(candidates []int, target int) [][]int {
    sort.Ints(candidates)
    candidates = unique(candidates)
    ans := [][]int{}
    dfs(candidates, target, []int{}, &ans)
    return ans
}

func main() {
    fmt.Println(combinationSum([]int{2, 3, 7}, 18))
}
