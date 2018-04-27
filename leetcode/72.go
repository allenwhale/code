package main

import "fmt"

func min(s... int) int {
    res := s[0]
    for _, x := range s {
        if x < res {
            res = x
        }
    }
    return res
}

func minDistance(word1 string, word2 string) int {
    l1, l2 := len(word1), len(word2)
    if l1 == 0 || l2 == 0 {
        return l1 + l2
    }
    dp := make([][]int, l1)
    for i := 0 ; i < l1 ; i++ {
        dp[i] = make([]int, l2)
    }
    for i := 0 ; i < l1 ; i++ {
        for j := 0 ; j < l2 ; j++ {
            if i == 0 && j == 0 {
                if word1[i] == word2[j] {
                    dp[0][0] = 0
                } else {
                    dp[0][0] = 1
                }
            } else if i == 0 {
                if word1[i] == word2[j] {
                    dp[i][j] = j
                } else {
                    dp[i][j] = dp[i][j - 1] + 1
                }
            } else if j == 0 {
                if word1[i] == word2[j] {
                    dp[i][j] = i
                } else {
                    dp[i][j] = dp[i - 1][j] + 1
                }
            } else {
                if word1[i] == word2[j] {
                    dp[i][j] = dp[i - 1][j - 1]
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                }
            }
        }
    }
    return dp[l1 - 1][l2 - 1]
}
func main() {
    fmt.Println(minDistance("horse", "ros"))
    fmt.Println(minDistance("intention", "execution"))
    fmt.Println(minDistance("a", "ab"))
}
