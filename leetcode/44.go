package main

import "fmt"

func isMatch(s string, p string) bool {
    ss, pp := make([]byte, len(s) + 1), make([]byte, len(p) + 1)
    for i := 0 ; i < len(s) ; i++ {
        ss[i + 1] = s[i]
    }
    for i := 0 ; i < len(p) ; i++ {
        pp[i + 1] = p[i]
    }
    dp := [][]bool{}
    for i := 0 ; i < len(ss) ; i++ {
        dp = append(dp, make([]bool, len(pp)))
    }
    dp[0][0] = true
    for i := 1 ; i < len(pp) ; i++ {
        dp[0][i] = dp[0][i - 1] && pp[i] == '*'
    }
    for i := 1 ; i < len(ss) ; i++ {
        for j := 1 ; j < len(pp) ; j++ {
            if pp[j] == '*' {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1]
            } else {
                dp[i][j] = dp[i - 1][j - 1] && (pp[j] == '?' || pp[j] == ss[i])
            }
        }
    }
    return dp[len(s)][len(p)]
}
func main() {
    fmt.Println(isMatch("aa", "a"))
    fmt.Println(isMatch("aa", "*"))
    fmt.Println(isMatch("cb", "*a"))
    fmt.Println(isMatch("adceb", "*a*b"))
    fmt.Println(isMatch("acdcb", "a*c?b"))
}
