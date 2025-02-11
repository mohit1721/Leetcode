class Solution {
public:
    string removeOccurrences(string &s, string &part) {
        int n = s.length();
        int m=part.length();
    //    1.
        // while(m <= n && n>0 && s.find(part) < n ){
        //     s.erase(s.find(part) , m);
        // }
        // return s;
        // 2.
        int foundPos = s.find(part);
        while(foundPos != string::npos){
            s.erase(foundPos, m);
            // re-find that part
            foundPos = s.find(part);
        }
        return s;
    }
};