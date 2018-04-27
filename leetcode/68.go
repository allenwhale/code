package main
import "github.com/kr/pretty"

import "bytes"
func fullJustify(words []string, maxWidth int) []string {
    curLen, curNum := 0, 0
    arrange, totalLen, tmp := [][]int{}, []int{}, []int{}
    for i := 0 ; i < len(words) ; i++ {
        if curLen + curNum + len(words[i]) <= maxWidth {
            curLen, curNum = curLen + len(words[i]), curNum + 1
            tmp = append(tmp, i)
        } else {
            arrange, totalLen, tmp = append(arrange, append([]int(nil), tmp...)), append(totalLen, curLen), []int{i}
            curLen, curNum = len(words[i]), 1
        }
    }
    if len(tmp) != 0 {
        arrange, totalLen = append(arrange, append([]int(nil), tmp...)), append(totalLen, curLen)
    }
    ans := []string{}
    var buf bytes.Buffer
    for i := 0 ; i < len(arrange) - 1 ; i++ {
        buf.Reset()
        space := maxWidth - totalLen[i]
        var eachSpace, extraSpace int
        if len(arrange[i])  > 1 {
            eachSpace, extraSpace = space / (len(arrange[i]) - 1), space % (len(arrange[i]) - 1)
        }
        for j := 0 ; j < len(arrange[i]) ; j++ {
            buf.WriteString(words[arrange[i][j]])
            if !((j == len(arrange[i]) - 1 && len(arrange[i]) == 1) || j == len(arrange[i]) - 1) {
                buf.Write(bytes.Repeat([]byte(" "), eachSpace))
                if j < extraSpace{
                    buf.WriteByte(' ')
                }
            }
        }
        if len(arrange[i]) == 1 {
            buf.Write(bytes.Repeat([]byte(" "), space))
        }
        ans = append(ans, buf.String())
    }
    buf.Reset()
    for i := 0 ; i < len(arrange[len(arrange) - 1]) ; i++ {
        buf.WriteString(words[arrange[len(arrange) - 1][i]])
        if i != len(arrange[len(arrange) - 1]) - 1 {
            buf.WriteByte(' ')
        }
    }
    buf.Write(bytes.Repeat([]byte(" "), maxWidth - totalLen[len(totalLen) - 1] - len(arrange[len(arrange) - 1]) + 1))
    ans = append(ans, buf.String())
    return ans
}
func main() {
    pretty.Println(fullJustify([]string{"Science","is","what","we","understand","well","enough","to","explain", "to","a","computer.","Art","is","everything","else","we","do"}, 20))
    pretty.Println(fullJustify([]string{"What","must","be","acknowledgment","shall","be"}, 16))
}
