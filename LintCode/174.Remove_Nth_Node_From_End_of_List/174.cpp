/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution1 {
public:
    /*
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        // write your code here
        int length = cntLength(head, 0);
        ListNode * cur = head;
        for (int i = 0; i < (length - n - 1); ++i) {
            cout<<(cur->val)<<endl;
            cur = cur->next;
        }
        
        if (head->next == nullptr) {
            return NULL;
        } else if (cur == head) {
            return head->next;
        } else {
            cur->next = cur->next->next;
            return head;
        }
    }

private:
    int cntLength(ListNode * head, int n) {
        if (!head) {
            return n;
        } else {
            return cntLength(head->next, n + 1);
        }
    }
};





// Time:  O(n)
// Space: O(1)
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy{0};
        dummy.next = head;
        auto slow = &dummy;
        auto fast = &dummy;

        // fast is n-step ahead.
        while (n > 0) {
            fast = fast->next;
            --n;
        }

        // When fast reaches the end, slow must be nth to last node.
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        auto node_to_delete = slow->next;
        slow->next = slow->next->next;
        delete node_to_delete;

        return dummy.next;
    }
};