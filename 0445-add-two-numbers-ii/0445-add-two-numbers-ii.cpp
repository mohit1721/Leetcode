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
    ListNode* reverse(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        s2.push(l2->val);
        l2 = l2->next;
    }
    // Step 2: Add the numbers
    ListNode* ansHead = NULL;
    ListNode* ansTail = NULL;
    int carry = 0;

     while (!s1.empty() || !s2.empty()) {

        int l1val = !s1.empty() ? s1.top() : 0;
        if(!s1.empty())
            s1.pop();
        int l2val = !s2.empty() ? s2.top() : 0;
        if(!s2.empty())
            s2.pop();

        int sum = carry + l1val + l2val;

        int digit = sum % 10;
        carry = sum / 10;

        ListNode* newNode = new ListNode(digit);
        //1st node
        if (!ansHead) {
            ansHead = newNode;
            ansTail = newNode;
        } else {
            ansTail->next = newNode;
            ansTail = newNode;
        }
    }
    // Case d: Carry remaining
    if (carry != 0) {
        // int sum = carry;
        // int digit = sum % 10;
        // carry = sum / 10;
        ListNode* newNode = new ListNode(carry);
        ansTail->next = newNode;
        ansTail = newNode;
    }
    // ek baar reverse
    ansHead = reverse(ansHead);
    return ansHead;
}
};