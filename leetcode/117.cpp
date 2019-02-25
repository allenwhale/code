#include <bits/stdc++.h>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {
    }
};
class Solution {
public:
TreeLinkNode *next(TreeLinkNode *&p, TreeLinkNode *c){
    while (p != NULL) {
        if (p->left != c && p->left != NULL) {
            return p->left;
        }
        if (p->right != c && p->right != NULL) {
            auto res = p->right;
            p = p->next;
            return res;
        }
        p = p->next;
    }
    return NULL;
}
void connect(TreeLinkNode *root) {
    TreeLinkNode *p = root, *c = next(root, NULL), *nc, *tc;

    while (c != NULL) {
        tc = c;
        do {
            nc = next(p, c);
            c->next = nc;
            c = nc;
        } while (nc != NULL);
        p = tc;
        c = next(p, NULL);
    }
}
};

int main() {
    auto root = new TreeLinkNode(1);

    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->right->left = new TreeLinkNode(5);
    Solution s;
    s.connect(root);

	/* code */
    return 0;
}
