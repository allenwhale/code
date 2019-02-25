#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int			val;
    TreeNode *	left;
    TreeNode *	right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Codec {
public:

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    if (root == NULL) return "[]";
    vector<TreeNode *> nodes;
    nodes.push_back(root);
    int i = 0;
    while (i < nodes.size()) {
        int sz = nodes.size();
        while (i < sz) {
            if (nodes[i]) {
                nodes.push_back(nodes[i]->left);
                nodes.push_back(nodes[i]->right);
            }
            i++;
        }
    }
    while (nodes.back() == NULL)
        nodes.pop_back();
    string res = "[";
    for (auto n : nodes) {
        if (n)
            res += to_string(n->val) + ",";
        else
            res += "null,";
    }
    res.back() = ']';
    return res;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(const string &data)
{
    if (data == "[]") return NULL;
    vector<TreeNode *> nodes;
    int i = 0;
    while (data[i] != ']') {
        i++;
        if (isdigit(data[i]) || data[i] == '-') {
            int sgn = 1;
            if (data[i] == '-') {
                sgn = -1;
                i++;
            }
            int tmp = 0;
            while (isdigit(data[i])) {
                tmp = tmp * 10 + data[i] - '0';
                i++;
            }
            nodes.push_back(new TreeNode(tmp * sgn));
        } else {
            nodes.push_back(NULL);
            i += 4;
        }
    }
    int l1 = 0, r1 = 1;
    int l2 = 1, r2 = 1;
    while (r2 < nodes.size()) {
        while (l1 < r1) {
            if (nodes[l1]) {
                if (r2 < nodes.size())
                    nodes[l1]->left = nodes[r2++];
                if (r2 < nodes.size())
                    nodes[l1]->right = nodes[r2++];
            }
            l1++;
        }
        l1 = l2, r1 = r2;
        l2 = r2;
    }
    return nodes[0];
}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main(int argc, char const *argv[])
{
    Codec c;

    cout << c.serialize(c.deserialize("[]"));
    return 0;
}
