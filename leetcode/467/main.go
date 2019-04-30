package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func findSubstringInWraproundString(p string) int {
	cnt := make([]int, 26)
	len := 0
	for i, c := range p {
		cc := int(byte(c) - 'a')
		if i > 0 && (int(p[i-1]) == int(p[i])-1 || (p[i-1] == 'z' && p[i] == 'a')) {
			len = len + 1
		} else {
			len = 1
		}
		cnt[cc] = max(cnt[cc], len)
	}
	ans := 0
	for _, x := range cnt {
		ans = ans + x
	}
	return ans
}
func main() {

}
