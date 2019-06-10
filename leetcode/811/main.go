package main

import (
	"strconv"
	"strings"

	"github.com/kr/pretty"
)

func subdomainVisits(cpdomains []string) []string {
	cnt := make(map[string]int, len(cpdomains))
	for _, s := range cpdomains {
		ss := strings.Split(s, " ")
		c, _ := strconv.Atoi(ss[0])
		d := ss[1]
		for len(d) != 0 {
			cnt[d] = cnt[d] + int(c)
			nxt := strings.IndexByte(d, '.')
			if nxt == -1 {
				d = ""
			} else {
				d = d[nxt+1:]
			}
		}
	}
	res := make([]string, 0, len(cnt))
	for d := range cnt {
		res = append(res, strconv.Itoa(cnt[d])+" "+d)
	}
	return res
}
func main() {
	pretty.Println(subdomainVisits([]string{"9001 discuss.leetcode.com"}))
	pretty.Println(subdomainVisits([]string{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"}))
}
