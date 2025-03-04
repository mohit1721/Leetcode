class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // brute force - 3 vectors
        vector<int>less;
        vector<int>equal;
        vector<int>greater;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < pivot)
            {
                less.push_back(nums[i]);
            }
            else if(nums[i]== pivot){
                equal.push_back(nums[i]);
            }
            else{
                greater.push_back(nums[i]);
                }
        }
//less wale m hi baki k add kr do 
for(int& num : equal){
    less.push_back(num);
}
for(int& num: greater){
    less.push_back(num);
}


return less;
        
    }
};
