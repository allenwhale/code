package main

import "sort"

func dfs(x string, G map[string][]string, ans *[]string) {
	for len(G[x]) != 0 {
		v := G[x][0]
		G[x] = G[x][1:]
		dfs(v, G, ans)
	}
	*ans = append(*ans, x)
}
func findItinerary(tickets [][]string) []string {
	G := make(map[string][]string)
	for _, t := range tickets {
		G[t[0]] = append(G[t[0]], t[1])
	}
	for k := range G {
		sort.Strings(G[k])
	}
	ans := make([]string, 0, len(tickets))
	dfs("JFK", G, &ans)
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return ans
}
func main() {

}
