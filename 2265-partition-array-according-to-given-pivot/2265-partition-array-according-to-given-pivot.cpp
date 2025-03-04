class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // 2 ptr
        int n =nums.size();
        
        int less=0, greater=n-1;
        int lessPtr=0, greaterPtr=n - 1;
        vector<int>ans(n);
        while(less <= n-1 && greater >= 0 ){
            if(nums[less] < pivot){
                    ans[lessPtr]= nums[less];
                    lessPtr++;
            }
            if(nums[greater] > pivot){
                ans[greaterPtr] = nums[greater];
                greaterPtr--;
            }
             less++;
             greater--;
        }
// ab jo bachega, wo only == pivote honge..fill it
while(lessPtr <= greaterPtr){
    ans[lessPtr]=pivot;
    lessPtr++;
}
return ans;

    }
};
