package main

import "fmt"

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func trap(height []int) int {
    stk := []int{}
    ans := 0
    for i := 0 ; i < len(height) ; i++ {
        for len(stk) != 0 && height[stk[len(stk) - 1]] < height[i] {
            var x int
            x, stk = stk[len(stk) - 1], stk[: len(stk) - 1]
            if len(stk) == 0 {
                break
            }
            ans += (i - stk[len(stk) - 1] - 1) * (min(height[i], height[stk[len(stk) - 1]]) - height[x])
        }
        if len(stk) == 0 || height[i] <= height[stk[len(stk) - 1]] {
            stk = append(stk, i)
        }
    }
    return ans
}

func main() {
    fmt.Println(trap([]int{5,2,1,2,1,5}))
}
