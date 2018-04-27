package main

import "fmt"

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func jump(nums []int) int {
    last, farthest, ans := 0, 0, 0
    for i := 0 ; i < len(nums) ; i++ {
        farthest = max(farthest, i + nums[i])
        if i == last && i != len(nums) - 1 {
            ans, last = ans + 1, farthest
        }
    }
    return ans
}

func main() {
    fmt.Println(jump([]int{2,3,1,1,4}))
}
