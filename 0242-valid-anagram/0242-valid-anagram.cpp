class Solution {
public:
    bool isAnagram(string &s, string &t) {
//my approach-->frq map lo..ek string k liye ++ , dusre k liye -- , baki re iterate..& check agar -ve/>=1 freq mile to false ...otherwise its true 
        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < freq.size(); i++) {
 
             if (freq[i] >= 1)
                return  false;
         
                    if(freq[i] < 0) 
                    return false;
            }

        return true; //
    }

}
;