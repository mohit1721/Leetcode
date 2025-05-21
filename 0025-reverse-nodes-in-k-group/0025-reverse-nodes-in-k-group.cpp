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
ListNode* reverse(ListNode* st, ListNode* end){
    ListNode* curr=st;
    ListNode* prev=NULL;
    while(curr != end){
        ListNode* forward = curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;

    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(!head || !head->next) return head;
       
        int count=0;
        ListNode* temp = head;
        while(temp && count<k){
            temp=temp->next;
            count++;
        }
        if(count<k) return head;
        ListNode* firstKRevHead = reverse(head, temp);//strt, end

        head->next = reverseKGroup(temp, k);//***
        return firstKRevHead;
        
    }
};