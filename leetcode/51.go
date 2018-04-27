package main

import "github.com/kr/pretty"

func dfs(id, n, v, l, r int, status []uint, ans *[][]uint) {
    if id == n {
        newStatus := make([]uint, len(status))
        copy(newStatus, status)
        *ans = append(*ans, newStatus)
    }
    mask := v | l | r
    for i := uint(0) ; i < uint(n) ; i++ {
        if (mask & (1 << i)) == 0 {
            status[id] = i
            dfs(id + 1, n, v | (1 << i), (l | (1 << i)) >> 1, (r | (1 << i)) << 1, status, ans)
        }
    }
}

func solveNQueens(n int) [][]string {
    status := make([]uint, n)
    ansStatus := [][]uint{}
    dfs(0, n, 0, 0, 0, status[:], &ansStatus)
    ans, s := [][]string{}, make([]byte, n)
    for i := 0 ; i < len(s) ; i++ {
        s[i] = '.'
    }
    for i := 0 ; i < len(ansStatus) ; i++ {
        tmp := []string{}
        for j := 0 ; j < n ; j++ {
            s[ansStatus[i][j]] = 'Q'
            tmp = append(tmp, string(s))
            s[ansStatus[i][j]] = '.'
        }
        ans = append(ans, tmp)
    }
    return ans
}

func main() {
    pretty.Println(solveNQueens(4))
}
