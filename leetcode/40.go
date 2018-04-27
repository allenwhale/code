package main

import "fmt"

import "sort"

func dfs(candidates []int, target int, now []int, ans *[][]int) {
    //fmt.Println(now, target)
    if target < 0 {
        return
    }
    if target == 0 {
        newNow := make([]int, len(now))
        copy(newNow, now)
        *ans = append(*ans, newNow)
        return
    }
    if len(candidates) == 0 {
        return
    }
    for i := 0 ; i < len(candidates) ; i++ {
        if i != 0 && candidates[i] == candidates[i - 1] {
            continue
        }
        dfs(candidates[i + 1 :], target - candidates[i], append(now, candidates[i]), ans)
    }
}

func combinationSum2(candidates []int, target int) [][]int {
    sort.Ints(candidates)
    ans := [][]int{}
    dfs(candidates, target, []int{}, &ans)
    return ans
}

func main() {
    fmt.Println(combinationSum2([]int{2,5,2,1,2}, 5))
}

