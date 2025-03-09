class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0, e=n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
        // 
        if(nums[mid] ==  target)
        {
            return mid;
        }
        // check kon sa half sorted h
        if(nums[s] <= nums[mid]) //left half is sorted
        {
            // Check karo ki target left sorted part me hai ya nahi

             if(nums[s] <= target && target < nums[mid]){
                e=mid-1; // Agar target left sorted range me hai toh right half ko discard kardo
            }
            else{
                s=mid+1; // Nahi toh right half pe jao
            }
        }
        else{ //// Right half is sorted

            if(nums[mid] < target && target <= nums[e]  )
            {
                s=mid+1; // Agar target right sorted range me hai toh left half ko discard kardo
            }
            else{
                e=mid-1; // Nahi toh left half pe jao
            }

        }
            
        }
 return -1;
 
 
     }
};