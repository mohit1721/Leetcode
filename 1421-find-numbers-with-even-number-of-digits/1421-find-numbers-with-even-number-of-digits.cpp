class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
            int n=nums.size();
            int i=0;
            int totalCnt=0;
            while(i<n)
            {
                string num = to_string(nums[i]);
                totalCnt+= (num.length()%2==0) ? 1 : 0;  
                i++;  
            
            }

return totalCnt;
    }
};