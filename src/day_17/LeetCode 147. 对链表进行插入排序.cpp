/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
 class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        while (head)
        {
            ListNode *next = head->next;
            ListNode *p = dummy;
            while (p->next && p->next-> val <= head->val) p = p->next;

            head->next = p->next;
            p->next = head;

            head = next;
        }
        return dummy->next;
    }
};

class Solution2 {
public:
    ListNode* insertionSortList(ListNode* head) {
        auto dummy = new ListNode(-1);
        for(auto p = head; p; ){
            auto cur = dummy, next = p->next;
            while(cur->next && cur->next->val <= p->val) cur = cur->next;
            p->next = cur->next;
            cur->next = p;
            p = next;
        }
        return dummy->next;
    }
};