#include <bits/stdc++.h>
using namespace std;
class TimeMap {
  public:
    unordered_map<string, map<int, string>> data;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        data[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto it = data[key].upper_bound(timestamp);
        return it == data[key].begin() ? "" : (--it)->second;
    }
};
int main() {
    return 0; //
}