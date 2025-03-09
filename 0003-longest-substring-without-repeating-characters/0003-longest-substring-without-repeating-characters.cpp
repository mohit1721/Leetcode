class Solution {
public:
    int lengthOfLongestSubstring(string& str) {
        // max- sliding window
        int res = INT_MIN;
        int s=0;
        int e=0;
        int n= str.length();
        if(str.empty()) return 0;
        unordered_map<char,int>mp;//
        while(e<n){
            // 
            mp[str[e]]++;

            while(mp[str[e]] > 1)
            {
                mp[str[s]]--;
                s++;
            }
            res = max(res, (e-s+1));
                e++;

        }

        return res;
    }
};