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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersC(l1, l2, 0);
    }
    ListNode* addTwoNumbersC(ListNode* l1, ListNode* l2, int c) {
        if(l1&&l2) {
            int value = l1->val + l2->val + c;
            ListNode* node = l1;
            node->val = value%10;
            node->next = addTwoNumbersC(l1->next, l2->next, value/10);
            return node;
        } if(l1||l2) {
            ListNode* node = l1?l1:l2;
            int value = node->val + c;
            node->val = value%10;
            node->next = addTwoNumbersC(node->next, NULL, value/10);
            return node;
        } else if(c>0) {
            ListNode node = struct ListNode(c,NULL);
            return &node;
        } else {
            return NULL;
        }
    }
};