from __future__ import print_function

def solution(s):
    ans, cnt = 0, 0
    for x in s:
        if x == '>':
            cnt += 1
        elif x == '<':
            ans += cnt
    return ans * 2
    
if __name__ == "__main__":
    print(solution(">----<"))
    print(solution("<<>><"))