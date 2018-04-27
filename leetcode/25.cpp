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
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode nil(0), *cur = head, *pre, *nxt;
            int num = 0;
            while(cur)
                num++, cur = cur->next;
            printf("num %d\n", num);
            nil.next = head;
            pre = &nil;
            while(num >= k){
                cur = pre->next;
                nxt = cur->next;
                for(int i = 0 ; i < k - 1 ; i++){
                    cur->next = nxt->next;
                    nxt->next = pre->next;
                    pre->next = nxt;
                    nxt = cur->next;
                }
                pre = cur;
                num -= k;
            }
            return nil.next;
        }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(0), *res = head;
    for(int i = 1 ; i <= 4 ; i++)
        res = res->next = new ListNode(i);
    auto ptr = sol.reverseKGroup(head->next, 3);
    printf("%p\n", ptr);
    while(ptr)
        printf("%d\n", ptr->val), ptr = ptr->next;
    return 0;
}
