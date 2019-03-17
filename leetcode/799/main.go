package main

import "fmt"

func champagneTower(poured int, query_row int, query_glass int) float64 {
	dp := []float64{float64(poured)}
	for i := 0; i < query_row; i++ {
		ndp := make([]float64, i+2)
		for j := 0; j < i+1; j++ {
			if dp[j] > 1. {
				ndp[j] = ndp[j] + (dp[j]-1.0)*0.5
				ndp[j+1] = ndp[j+1] + (dp[j]-1.0)*0.5
			}
		}
		dp = ndp
	}
	if dp[query_glass] < 1. {
		return dp[query_glass]
	} else {
		return 1.
	}
}
func main() {
	fmt.Println(champagneTower(1, 1, 1))
	fmt.Println(champagneTower(2, 1, 1))
}
