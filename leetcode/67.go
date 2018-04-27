package main
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func addBinary(a string, b string) string {
    sa, sb := []byte(a), []byte(b)
    la, lb := len(a), len(b)
    for i := 0 ; i < la / 2 ; i++ {
        sa[i], sa[la - i - 1] = sa[la - i - 1], sa[i]
    }
    for i := 0 ; i < lb / 2 ; i++ {
        sb[i], sb[lb - i - 1] = sb[lb - i - 1], sb[i]
    }
    if la < lb {
        la, lb = lb, la
        sa, sb = sb, sa
    }
    for i := 0 ; i < la ; i++ {
        sa[i] = sa[i] - byte('0')
    }
    for i := 0 ; i < lb ; i++ {
        sb[i] = sb[i] - byte('0')
    }
    for i := 0 ; i < lb ; i++ {
        sa[i] += sb[i]
    }
    for i := 0 ; i < la - 1 ; i++ {
        if sa[i] >= 2 {
            sa[i] -= 2
            sa[i + 1]++
        }
    }
    if sa[la - 1] >= 2 {
        sa[la - 1] -= 2
        sa = append(sa, byte(1))
        la++
    }
    for i := 0 ; i < la / 2 ; i++ {
        sa[i], sa[la - i - 1] = sa[la - i - 1], sa[i]
    }
    for i := 0 ; i < la ; i++ {
        sa[i] = sa[i] + byte('0')
    }
    return string(sa)
}

func main() {
}
