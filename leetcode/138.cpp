#include <bits/stdc++.h>
using namespace std;
class Node
{
  public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random)
    {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution
{
  public:
    unordered_map<Node *, Node *> copied;
    Node *copyNode(Node *n)
    {
        if (n == NULL)
            return NULL;
        if (copied.find(n) != copied.end())
        {
            return copied[n];
        }
        copied[n] = new Node(n->val, NULL, NULL);
        copied[n]->next = copyNode(n->next);
        copied[n]->random = copyNode(n->random);
        return copied[n];
    }
    Node *copyRandomList(Node *head)
    {
        copied.clear();
        return copyNode(head);
    }
};
int main()
{

    return 0;
}