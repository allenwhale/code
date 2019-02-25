#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {
    };
};
class Solution {
public:
UndirectedGraphNode* get(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &m,
                         UndirectedGraphNode *n){
    if (m.find(n) == m.end()) {
        m[n] = new UndirectedGraphNode(n->label);
    }
    return m[n];
}
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL) {
        return NULL;
    }
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;
    unordered_set<UndirectedGraphNode*> vis;
    queue<UndirectedGraphNode*> q;
    auto res = get(mapping, node);
    q.push(node);
    vis.insert(node);
    while (!q.empty()) {
        auto n = q.front();
        q.pop();
        auto nn = get(mapping, n);
        for (auto v:n->neighbors) {
            nn->neighbors.push_back(get(mapping, v));
            if (vis.find(v) == vis.end()) {
                vis.insert(v);
                q.push(v);
            }
        }
    }
    return res;
}
};
int main(int argc, char const *argv[]) {
	/* code */
    return 0;
}
