class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    //#  better
    unordered_map<int,int>mp; //value -> index 

    for(int i=0;i<n;i++)
    {
        int num = nums[i];
        int moreNeeded = target - num;
        if(mp.count(moreNeeded))//present in map
        {
            return {i, mp[moreNeeded]}; // returned both index
        }
        //else , mapm num -> index
        mp[num] = i;
    }
     
return {-1,-1};




    }
};