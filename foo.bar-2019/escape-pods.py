from __future__ import print_function


class Edge:
    def __init__(self, v1, v2, f, c):
        self.v1 = v1
        self.v2 = v2
        self.f = f
        self.c = c


class Dinic:
    def __init__(self, n):
        self.n = n
        self.E = []
        self.vc = [list([]) for _ in range(self.n)]

    def add_edge(self, a, b, c):
        self.vc[a].append(len(self.E))
        self.E.append(Edge(a, b, c, c))
        self.vc[b].append(len(self.E))
        self.E.append(Edge(a, b, 0, c))

    def bfs(self, s, t):
        self.dep = [-1 for _ in range(self.n)]
        self.dep[s] = 0
        q = [s]
        while len(q) > 0:
            v, q = q[0], q[1:]
            for eid in self.vc[v]:
                e = self.E[eid]
                if e.f > 0 and self.dep[e.v2] == -1:
                    self.dep[e.v2] = self.dep[v] + 1
                    q.append(e.v2)
        return self.dep[t]

    def dfs(self, x, df, t):
        if x == t:
            return df
        res = 0
        for eid in self.vc[x]:
            e = self.E[eid]
            if e.f > 0 and self.dep[e.v2] == self.dep[x] + 1:
                f = self.dfs(e.v2, min(df, e.f), t)
                e.f -= f
                df -= f
                res += f
                self.E[eid ^ 1].f += f
                if df == 0:
                    return res
        if res == 0:
            self.dep[x] = -1
        return res

    def solve(self, s, t):
        f = 0
        while self.bfs(s, t) != -1:
            f += self.dfs(s, 0x3f3f3f3f, t)
        return f


def solution(entrances, exits, path):
    N = len(path)
    S, T = N, N + 1
    dinic = Dinic(N + 2)
    for x in entrances:
        dinic.add_edge(S, x, 0x3f3f3f3f)
    for x in exits:
        dinic.add_edge(x, T, 0x3f3f3f3f)

    for i, p in enumerate(path):
        for j, v in enumerate(p):
            dinic.add_edge(i, j, v)
    return dinic.solve(S, T)


if __name__ == "__main__":
    print(
        solution([0], [3],
                 [[0, 7, 0, 0], [0, 0, 6, 0], [0, 0, 0, 8], [9, 0, 0, 0]]))
    print(
        solution([0, 1], [4, 5],
                 [[0, 0, 4, 6, 0, 0], [0, 0, 5, 2, 0, 0], [0, 0, 0, 0, 4, 4],
                  [0, 0, 0, 0, 6, 6], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]))
    pass
