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
    ListNode *detectCycle(ListNode *head) {

        map<ListNode* , bool>mp;

        ListNode* temp=head;
        if(!temp) return NULL;
        while(temp){
            if(mp.count(temp)){
                return temp;
            }
            mp[temp]=true;
            temp= temp->next;
        }
        return NULL;
    }
};