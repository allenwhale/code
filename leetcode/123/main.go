package main

import (
	"fmt"
	"math"
)

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxProfit(prices []int) int {
	prices = append(prices, 0)
	d1 := [2]int{-prices[0], math.MinInt32}
	d2 := [2]int{math.MinInt32, math.MinInt32}
	for i := 1; i < len(prices)-1; i++ {
		d2[1] = Max(d2[1], d1[1]+prices[i])
		d2[0] = Max(d2[0], d1[0]+prices[i])
		d1[1] = Max(d1[1], d2[0]-prices[i+1])
		d1[0] = Max(d1[0], -prices[i])
	}
	return Max(Max(d2[0], d2[1]), 0)
}
func main() {
	fmt.Println(maxProfit([]int{3, 2, 6, 5, 0, 3}))
	fmt.Println(maxProfit([]int{3, 3, 5, 0, 0, 3, 1, 4}))
	fmt.Println(maxProfit([]int{1, 2, 3, 4, 5}))
	fmt.Println(maxProfit([]int{7, 6, 4, 3, 1}))
}
