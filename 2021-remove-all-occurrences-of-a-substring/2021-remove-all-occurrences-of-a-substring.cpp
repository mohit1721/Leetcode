class Solution {
public:
    string removeOccurrences(string &s, string &part) {
        int n = s.length();
        int m=part.length();
        while(m <= n && n>0 && s.find(part) < n ){
            s.erase(s.find(part) , m);
        }
        return s;
    }
};