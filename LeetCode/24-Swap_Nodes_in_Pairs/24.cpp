/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next)) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev, *cur, *next;
        prev = dummy;
        cur = prev->next;
        next = cur->next;

        while(next) {
            prev->next = next;
            next->next = cur;
            cur->next = next->next; //!

            prev = cur; //!
            cur = cur->next;
            next = cur?cur->next:nullptr;
        }

        return dummy->next;
    }
};
