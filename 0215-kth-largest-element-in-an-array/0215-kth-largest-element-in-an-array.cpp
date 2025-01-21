class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //#3. QuickSelect (Hoare's Algo)

    priority_queue<int>maxHeap(nums.begin(), nums.end());
    while(k>1)
    {
        if(!maxHeap.empty()){
            maxHeap.pop();
        }
        k--;
    }
    return maxHeap.top();
    }
};