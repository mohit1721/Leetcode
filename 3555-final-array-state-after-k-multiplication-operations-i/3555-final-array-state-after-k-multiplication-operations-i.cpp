class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minHeap;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            minHeap.push({nums[i] , i});
        }
        int i = 0;

        while(!minHeap.empty() && k-- ){
            auto tnode=minHeap.top();
            minHeap.pop();

            int val=tnode.first;
            int idx = tnode.second;
            //
            nums[idx] *=multiplier;
            minHeap.push({nums[idx] , idx});//repush***

        }
        return nums;
    }
};