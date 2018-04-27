package main

import "github.com/kr/pretty"
import "strings"

func lengthOfLastWord(s string) int {
    ss := strings.Split(s, " ")
    for i := len(ss) - 1 ; i >= 0 ; i-- {
        if ss[i] != "" {
            return len(ss[i])
        }
    }
    return 0
}

func main() {
    pretty.Println(lengthOfLastWord("test test"))
    pretty.Println(lengthOfLastWord(""))
}
