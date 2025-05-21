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
ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr){
        ListNode* forward = curr->next;
        curr->next = prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

bool compare(ListNode* l1, ListNode* l2){
    while(l1 && l2){
        if(l1->val != l2->val) return false;

        l1= l1->next;
        l2=l2->next;
    }
    return true;
}

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return true;
        //
        ListNode* midNode = findMid(head);

        ListNode* secondHalfRev= reverse(midNode);

        return compare(secondHalfRev, head);


    }
};