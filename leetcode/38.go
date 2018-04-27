package main

import "fmt"

import "bytes"

func countAndSay(n int) string {
    ans := []byte{1}
    for i := 0 ; i < n - 1 ; i++ {
        newAns, count := []byte{}, byte(1)
        for j := 1 ; j < len(ans) ; j++ {
            if ans[j] != ans[j - 1] {
                newAns, count = append(newAns, count, ans[j - 1]), 1
            } else {
                count++
            }
        }
        newAns = append(newAns, count, ans[len(ans) - 1])
        ans = newAns
    }
    var ansString bytes.Buffer
    for i := range(ans) {
        ansString.Write([]byte{byte('0') + ans[i]})
    }
    return ansString.String()
}

func main() {
    for i := 0 ; i < 10 ; i++ {
        fmt.Println(countAndSay(i));
    }
}

