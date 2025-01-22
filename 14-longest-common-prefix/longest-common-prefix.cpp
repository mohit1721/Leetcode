class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) return ""; // Edge case: if the input is empty

        string prefix=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            int j=0;
            while( j<strs[i].size() && prefix[j] == strs[i][j]){ ///***j<prefix.size() **
                j++;
            }
            prefix = prefix.substr(0,j);
            if(prefix == "")
            {
                return "";
            }
        }

return prefix;
    }
};