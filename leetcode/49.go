package main

import "github.com/kr/pretty"
import "math/rand"
const (
    MOD = int64(1000000009)
)

func hash(s string, seed []int64) int64 {
    res := int64(1)
    for i := 0 ; i < len(s) ; i++ {
        res = (res * seed[int(s[i]) - int('a')]) % MOD
    }
    return res
}

func groupAnagrams(strs []string) [][]string {
    mp := map[int64]int{}
    ans := [][]string{}
    seed := [26]int64{}
    for i := 0 ; i < 26 ; i++ {
        seed[i] = int64(rand.Int31())
    }
    find := func(x int64) int {
        val, ok := mp[x]
        if ok {
            return val
        }
        mp[x] = len(mp)
        ans = append(ans, []string{})
        return len(mp) - 1
    }
    for i := 0 ; i < len(strs) ; i++ {
        h := hash(strs[i], seed[:])
        ans[find(h)] = append(ans[find(h)], strs[i])
    }
    return ans
}

func main() {
    pretty.Println(groupAnagrams([]string{"eat","tea","tan","ate","nat","bat"}))
}
