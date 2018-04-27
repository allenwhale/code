#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *res = new ListNode(l1->val + l2->val), *root = res;
            l1 = l1->next, l2 = l2->next;
            while(l1 && l2){
                root->next = new ListNode(l1->val + l2->val);
                root = root->next, l1 = l1->next, l2 = l2->next;
            }
            while(l1){
                root->next = new ListNode(l1->val);
                root = root->next, l1 = l1->next;
            }
            while(l2){
                root->next = new ListNode(l2->val);
                root = root->next, l2 = l2->next;
            }
            root = res;
            while(root && root->next){
                root->next->val += root->val / 10;
                root->val %= 10;
                root = root->next;
            }
            if(root->val >= 10){
                root->next = new ListNode(root->val / 10);
                root->val %= 10;
            }
            return res;
        }
};

int main(){
    return 0;
}
