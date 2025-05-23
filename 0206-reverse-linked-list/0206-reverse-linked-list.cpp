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
ListNode* reverseR(ListNode* curr, ListNode* prev){
    //bc
    if(curr==NULL) return prev;
    //ek csse
    ListNode* forward = curr->next;
    curr->next=prev;
    //baki recursion
    return reverseR(forward , curr);
}
    ListNode* reverseList(ListNode* head) {
        /*
      ListNode* curr=head;
      ListNode*prev=NULL;
while(curr!=NULL)
{
 ListNode* forward=curr->next;
 curr->next=prev;
 prev=curr;
 curr=forward;

}
return prev;
*/
return reverseR(head, NULL);
     
    }
};