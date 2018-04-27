#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *nil = new ListNode(0);
            nil->next = head;
            ListNode *l = nil, *r = nil;
            for(int i = 0 ; i <= n ; i++)
                r = r->next;
            while(r)
                r = r->next, l = l->next;
            ListNode *go = l->next->next;
            delete l->next;
            l->next = go;
            head = nil->next;
            delete nil;
            return head;
        }
};

int main(){
    Solution sol;
    sol.removeNthFromEnd(new ListNode(1), 1);
    return 0;
}
