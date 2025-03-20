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
    ListNode* reverse(ListNode* start,ListNode* end)
    {
        ListNode* prev = NULL;
        ListNode* curr = start;
        while(curr != end)//**curr willl only play here now*
        {
            ListNode* forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;// only forward
        } 
        return prev;
    }



    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int count=0;

        ListNode* temp = head; //temp will go till k ***[end of first k group**]
           
    // Step 1: Check if there are at least `k` nodes available
        while(temp && count<k)
        {
            temp=temp=temp->next;
            count++;
        }
        if(count<k) return head;//// If less than k nodes, return as it is
        //else

    // Step 2: Reverse first `k` nodes

        ListNode* firstKGroupRevHead  = reverse(head,temp); //temp at end*

        // now for remainings-> use recursion
        // temp will head for next groups
        head->next = reverseKGroup(temp , k);//

return firstKGroupRevHead;

    }
};