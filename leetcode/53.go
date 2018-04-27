package main

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func maxSubArray(nums []int) int {
    ans, cur := nums[0], 0
    for i := 0 ; i < len(nums) ; i++ {
        if cur < 0 {
            cur = 0
        }
        cur = cur + nums[i]
        ans = max(ans, cur)
    }
    return ans
}

func main() {
}
