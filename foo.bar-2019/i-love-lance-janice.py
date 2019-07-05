from __future__ import print_function

m = {}
for i in range(26):
    m[chr(ord('a') + i)] = chr(ord('a') + 25 - i)


def solution(x):
    res = ""
    for c in x:
        if c in m:
            res += m[c]
        else:
            res += c
    return res


if __name__ == '__main__':
    print(solution("wrw blf hvv ozhg mrtsg'h vkrhlwv?"))
    print(solution("Yvzs! I xzm'g yvorvev Lzmxv olhg srh qly zg gsv xlolmb!!"))