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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *res = new ListNode(-1), *head = res;
            while(l1 && l2){
                if(l1->val < l2->val)
                    res = res->next = new ListNode(l1->val), l1 = l1->next;
                else
                    res = res->next = new ListNode(l2->val), l2 = l2->next;
            }
            while(l1)
                res = res->next = new ListNode(l1->val), l1 = l1->next;
            while(l2)
                res = res->next = new ListNode(l2->val), l2 = l2->next;
            return head->next;
        }
};
int main(){
    return 0;
}
