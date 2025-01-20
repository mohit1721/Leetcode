class Solution {
public:
    bool isAnagram(string s, string t) {
//my approach
        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < freq.size(); i++) {
            // if(s.length() > t.length())
        //    {
             if (freq[i] >= 1)
                return  false;
            // }
            // else{
                    if(freq[i] < 0) 
                    return false;
            }
        // }
        return true; //
    }

}
;