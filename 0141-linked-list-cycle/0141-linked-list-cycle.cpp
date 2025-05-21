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
    bool hasCycle(ListNode* head) {
        // Bontious Accoloite 
        ListNode* slow = head;
        ListNode* fast = head;

        if (!fast || !fast->next)
            return false;


        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) ///////
                return true;
        }
        return false;
    }
};