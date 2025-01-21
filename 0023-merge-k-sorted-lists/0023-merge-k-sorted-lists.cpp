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
class compare{
    public:
    bool operator()(ListNode* a, ListNode*b){
        return a->val > b->val ;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare>minHeap;
        int k= lists.size();
        if(k==0) return NULL;
        // process 1st element of l arrays
        for(int i=0;i<k;i++)
        {
            ListNode* node = lists[i];
            if(node!= NULL)
            minHeap.push(node);
        }
        // 

        ListNode* head=NULL;
        ListNode* tail=NULL;

        while(!minHeap.empty())
        {
            ListNode* fNode = minHeap.top();
            minHeap.pop();
            if(head==NULL)
            {
                //1st node
                head = fNode;
                tail = fNode;

            }
            else {
                //other than 1st node
            tail->next=fNode;
            tail=fNode;
            }
    // ab , agar iske neighbours exist krte h to usko daal do
    if(fNode->next)
    {
        minHeap.push(fNode->next);
    }

        }
return head;

    }
};