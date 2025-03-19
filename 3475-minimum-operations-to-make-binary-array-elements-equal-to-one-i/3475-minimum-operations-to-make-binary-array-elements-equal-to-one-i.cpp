class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
       int cnt=0;
int mini=-1;
for(int i=0;i<=n-3;i++)
{
 
if(nums[i]==0)
{
//flip 
nums[i] = 1-nums[i];
nums[i+1] = 1-nums[i+1];
nums[i+2] = 1-nums[i+2];

cnt++;
}


}
 
//then check agar ek v zero h to return -1 else return cnt

for(int i=0;i<n;i++){
if(nums[i]==0)
return -1;
}

return cnt;
    }
};