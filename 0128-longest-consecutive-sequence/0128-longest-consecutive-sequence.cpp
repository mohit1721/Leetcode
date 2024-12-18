class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //  optimized 
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> st ;
int maxLen =0 ;
        for(int x : nums)
        {
            st.insert(x);
        } 

        //
        for(int num: st)
        {

            //new sequence mil rha to set to uske num-1 present nhi hi hoga
            if(st.count(num-1) == 0)//set m num-1 nhi mila to.. uske aage num +1 khojne ka try
            {
                int cnt = 1;
                while(st.count(num + 1))//jb tk num+1 set m present h
                {
                num=num+1;
                cnt++;
                }
                //
                maxLen = max(maxLen , cnt); //update maxLen for current Sequence
            }
        }
     return maxLen ;   
    }
};