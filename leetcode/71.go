package main
import "github.com/kr/pretty"
import "strings"
func simplifyPath(path string) string {
    paths, pathStk := strings.Split(path, "/"), []string{}
    for _, p := range paths[1 :] {
        if p == ".." {
            if len(pathStk) > 0 {
                pathStk = pathStk[: len(pathStk) - 1]
            }
        } else if p != "." && len(p) > 0{
            pathStk = append(pathStk, p)
        }
    }
    return "/" + strings.Join(pathStk, "/")
}
func main() {
    pretty.Println(simplifyPath("/home/./../allenwhale/../../"))
}
