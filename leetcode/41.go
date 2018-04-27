package main

import "fmt"

func firstMissingPositive(nums []int) int {
    for i := 0 ; i < len(nums) ; i++ {
        cur := i
        for nums[cur] - 1 != cur && nums[cur] > 0 && nums[cur] <= len(nums) && nums[cur] != nums[nums[cur] - 1]{
            nums[nums[cur] - 1], nums[cur] = nums[cur], nums[nums[cur] - 1]
        }
    }
    for i := 0 ; i < len(nums) ; i++ {
        if i + 1 != nums[i] {
            return i + 1
        }
    }
    return len(nums) + 1
}

func main() {
    fmt.Println(firstMissingPositive([]int{1, 1}))
}
