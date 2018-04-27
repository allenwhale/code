package main

import "github.com/kr/pretty"

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func canJump(nums []int) bool {
    farthest := 0
    for i := 0 ; i < len(nums) && i <= farthest ; i++ {
        farthest = max(farthest, i + nums[i])
    }
    return farthest >= len(nums) - 1
}

func main() {
}
