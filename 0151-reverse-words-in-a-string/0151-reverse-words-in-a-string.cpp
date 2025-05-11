class Solution {
public:
    // Accolite
    string reverseWords(string& s) {
       vector<string> ans;
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            ans.push_back(word);
        }

        reverse(ans.begin(), ans.end());

        string res = "";
        for (int i = 0; i < ans.size(); i++) {
            res += ans[i];
            if (i != ans.size() - 1)
                res += ' ';
        }

        return res;


    }
};