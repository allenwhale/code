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
        ListNode* swapPairs(ListNode* head) {
            ListNode **ptr = &head, *tmp, *tmp2; 
            while(*ptr && (*ptr)->next){
                tmp = *ptr;
                *ptr = (*ptr)->next;
                tmp2 = (*ptr)->next;
                (*ptr)->next = tmp;
                tmp->next = tmp2;
                ptr = &((*ptr)->next->next);
            }
            return head;
        }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(1), *res = head;
    for(int i = 2 ; i <= 4 ; i++)
        res = res->next = new ListNode(i);
    auto ptr = sol.swapPairs(head);
    printf("%p\n", ptr);
    while(ptr)
        printf("%d\n", ptr->val), ptr = ptr->next;

    return 0;
}
