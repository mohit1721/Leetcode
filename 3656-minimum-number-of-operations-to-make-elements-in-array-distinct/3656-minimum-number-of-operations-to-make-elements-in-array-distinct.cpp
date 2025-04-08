class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        unordered_map<int,int> hmap;

        for(int i=nums.size()-1;i>=0;i--)
        {
            if(hmap.count(nums[i])>0)
            {
                return (ceil((i+1)/3.0));   
            }
            hmap[nums[i]]++;
        }
        return 0;
    }
};