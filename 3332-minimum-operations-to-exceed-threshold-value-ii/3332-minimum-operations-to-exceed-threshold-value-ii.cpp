class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // min-heap lo
        priority_queue<long , vector<long> , greater<long>>minHeap(nums.begin(), nums.end());//heapify - O(log n)
        // maually loop se insert krne se O(n * log(n))**Lesson
        int operation=0;
        while(!minHeap.empty() && minHeap.top() < k){
            long smallest = minHeap.top();
            minHeap.pop();

            long secondSmallest = minHeap.top();
            minHeap.pop();

            minHeap.push((smallest * 2) + secondSmallest); //min(x, y) * 2 + max(x, y) ..think**
            operation ++;
        }
return operation;
    }
};