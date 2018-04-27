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
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
            for(auto &x : lists)
                if(x)pq.push({x->val, x});
            ListNode *res = new ListNode(0), *head = res;
            while(!pq.empty()){
                auto x = pq.top();
                pq.pop();
                res = res->next = new ListNode(x.first);
                if(x.second->next)
                    pq.push({x.second->next->val, x.second->next});
            }
            return head->next;
        }
};

int main(){
    return 0;
}
