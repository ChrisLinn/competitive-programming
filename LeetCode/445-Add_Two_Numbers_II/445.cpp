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
        stack<int> stk1, stk2;
        ListNode* res = new ListNode(-1);
        int carry = 0;
        
        while(l1->next) {
            // cout<<(l1->val);
            stk1.push(l1->val);
            l1 = (l1->next);
        }
        stk1.push(l1->val);
        // cout<<(l1->val)<<endl;
        
        while(l2->next) {
            // cout<<(l2->val);
            stk2.push(l2->val);
            l2 = (l2->next);
        }
        stk2.push(l2->val);
        // cout<<(l2->val)<<endl;
        
        while(!stk1.empty() && !stk2.empty()) {
            ListNode* node = new ListNode((stk1.top() + stk2.top()  + carry)%10);
            carry = (stk1.top() + stk2.top() + carry)/10;
            if(res->val != -1){
                node->next = res;
            }
            res = node;
            stk1.pop();
            stk2.pop();    
        }

        if(!stk1.empty()) {
            while(!stk1.empty()) {
                ListNode* node = new ListNode((stk1.top() + carry)%10);
                carry = (stk1.top() + carry)/10;
                if(res->val != -1){
                    node->next = res;
                }
                res = node;
                stk1.pop();  
            }
        }
        if(!stk2.empty()) {
            while(!stk2.empty()) {
                ListNode* node = new ListNode((stk2.top() + carry)%10);
                carry = (stk2.top() + carry)/10;
                if(res->val != -1){
                    node->next = res;
                }
                res = node;
                stk2.pop();  
            }
        }
        if(carry != 0) {
            ListNode* node = new ListNode(carry);
            if(res->val != -1){
                node->next = res;
            }
            res = node;
        }
        
        return res;
    }
};