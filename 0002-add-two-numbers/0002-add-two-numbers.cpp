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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l2) return l1;
        if(!l1) return l2;
        ListNode* result = new ListNode(-1);
        ListNode* curr=result;
        int carry=0;
        while(l1 || l2){
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int value = val1+val2 + carry;//***
            
            carry=value/10;
            value=value%10;

            ListNode* newNode = new ListNode(value);
            curr->next = newNode;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;

            curr=curr->next;
        }
if(carry){
    ListNode* carryNode = new ListNode(carry);
    curr->next = carryNode;
}

return result->next;

    }
};