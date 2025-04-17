class Solution {
public:
    int countPairs(vector<int>& nums, int k) {

int n=nums.size();
int count=0;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(nums[i]==nums[j] && (i*j)% k ==0) count++;
    }
}
return count;




//  map<int,vector<int>>mp;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]].push_back(i);
//          }
//     int count=0;
// for(int i=0;i<nums.size();i++){
//     if(mp[nums[i]]==)
// }


    }
};