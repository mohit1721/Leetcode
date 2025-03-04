class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // better
        // count less < pivots & equal to pivot... then set 3 pointers acc. to theri lengths
        int n =nums.size();
        int less=0, equal =0 ;
        for(int i=0;i<n ;i++){
            if(nums[i] < pivot) less++;
            else if(nums[i]==pivot) equal++;
        }
    //   not set pointers acc. 
    int lessPtr=0, equalPtr = less, greaterPtr = less + equal ;
    vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i] < pivot && lessPtr <= less){
                ans[lessPtr]=nums[i];
                lessPtr++;
            }
            else if(nums[i] == pivot && equalPtr <= equal+less ){
                ans[equalPtr]=nums[i];
                equalPtr++;
            }
            else{
                ans[greaterPtr] = nums[i];
                greaterPtr++;
            }
        }

        return ans;
    }
};
