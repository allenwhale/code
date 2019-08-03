#include <bits/stdc++.h>
using namespace std;
class ExamRoom {
 public:
  int n;
  set<tuple<int, int, int, int>> s;
  unordered_map<int, pair<int, int>> m;
  ExamRoom(int N) { n = N; }
  void print() {
    printf("---\n");
    for (auto &t : s) printf("%d %d %d %d\n", get<0>(t), get<1>(t), get<2>(t), get<3>(t));
    for (auto &kv : m) printf("%d (%d %d)\n", kv.first, kv.second.first, kv.second.second);
    printf("---\n");
  }

  int seat() {
    if (m.size() == 0) {
      s.insert({-(n - 1), n - 1, 0, INT_MAX});
      m[0] = {INT_MIN, INT_MAX};
      return 0;
    } else {
      auto it = s.begin();
      int res = get<1>(*it);
      m[get<1>(*it)] = {get<2>(*it), get<3>(*it)};
      if (get<2>(*it) != INT_MIN) {
        m[get<2>(*it)] = {m[get<2>(*it)].first, get<1>(*it)};
        if (get<2>(*it) + 1 < get<1>(*it)) {
          s.insert({-(get<1>(*it) - get<2>(*it)) / 2, (get<1>(*it) + get<2>(*it)) / 2, get<2>(*it), get<1>(*it)});
        }
      }
      if (get<3>(*it) != INT_MAX) {
        m[get<3>(*it)] = {get<1>(*it), m[get<3>(*it)].second};
        if (get<1>(*it) + 1 < get<3>(*it)) {
          s.insert({-(get<3>(*it) - get<1>(*it)) / 2, (get<3>(*it) + get<1>(*it)) / 2, get<1>(*it), get<3>(*it)});
        }
      }
      s.erase(it);
      return res;
    }
  }

  void leave(int p) {
    int l = m[p].first, r = m[p].second;
    m.erase(p);
    if (l == INT_MIN && r == INT_MAX) {
      s.clear();
    } else if (l == INT_MIN) {
      s.erase({-p, 0, INT_MIN, p});
      s.erase({-(r - p) / 2, (r + p) / 2, p, r});
      s.insert({-r, 0, INT_MIN, r});
      m[r] = {INT_MIN, m[r].second};
    } else if (r == INT_MAX) {
      s.erase({-(n - 1 - p), n - 1, p, INT_MAX});
      s.erase({-(p - l) / 2, (p + l) / 2, l, p});
      s.insert({-(n - 1 - l), n - 1, l, INT_MAX});
      m[l] = {m[l].first, INT_MAX};
    } else {
      s.erase({-(r - p) / 2, (r + p) / 2, p, r});
      s.erase({-(p - l) / 2, (l + p) / 2, l, p});
      s.insert({-(r - l) / 2, (r + l) / 2, l, r});
      m[r] = {l, m[r].second};
      m[l] = {m[l].first, r};
    }
  }
};
int main() {
  ExamRoom ex(9);
  printf("%d\n", ex.seat());
  printf("%d\n", ex.seat());
  printf("%d\n", ex.seat());
  printf("%d\n", ex.seat());
  ex.print();
  ex.leave(4);
  ex.print();
  printf("%d\n", ex.seat());
  printf("%d\n", ex.seat());
  printf("%d\n", ex.seat());
  printf("%d\n", ex.seat());
  printf("%d\n", ex.seat());
  printf("%d\n", ex.seat());
  ex.leave(3);
  printf("%d\n", ex.seat());

  return 0;  //
}