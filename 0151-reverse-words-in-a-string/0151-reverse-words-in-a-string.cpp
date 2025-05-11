class Solution {
public:
    // Accolite
    string reverseWords(string& s) {
       stack<string> ans;
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            ans.push(word);
        }

 
        string res = "";
       while(!ans.empty()){
        res+=ans.top();
        ans.pop();
        res+=' ';
       }

        return res.substr(0, res.length()-1);


    }
};