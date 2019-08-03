package main

func dfs(x, t int, graph [][]int, now []int, ans *[][]int) {
	now = append(now, x)
	if x == t {
		*ans = append(*ans, append([]int{}, now...))
		return
	}
	for _, v := range graph[x] {
		dfs(v, t, graph, now, ans)
	}
	now = now[:len(now)-1]
}
func allPathsSourceTarget(graph [][]int) [][]int {
	S, T := 0, len(graph)-1
	ans := [][]int{}
	dfs(S, T, graph, []int{}, &ans)
	return ans
}

func main() {}
