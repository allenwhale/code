package main

import "github.com/kr/pretty"

func dfs(id, n, v, l, r int, ans *int) {
    if id == n {
        *ans = *ans + 1
    }
    mask := v | l | r
    for i := uint(0) ; i < uint(n) ; i++ {
        if (mask & (1 << i)) == 0 {
            dfs(id + 1, n, v | (1 << i), (l | (1 << i)) >> 1, (r | (1 << i)) << 1, ans)
        }
    }
}

func totalNQueens(n int) int {
    ans := 0
    dfs(0, n, 0, 0, 0, &ans)
    return ans
}

func main() {
    pretty.Println(totalNQueens(4))
}

