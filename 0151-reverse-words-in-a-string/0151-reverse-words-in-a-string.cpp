class Solution {
public:
    // Accolite
    string reverseWords(string& s) {
        // A. Reverse whole String s
        // jb tk character milta h assign to r
        // else,agar space milta h to,reverse the word b.w l & r
        //  r ko v to aage badhao** gltiii
        // l ko v to ab aage badhana h ..jo ki ab r k paas ayega
        // return only r-1

        int n = s.length();
        int i=0;
        int l=0,r=0;
        reverse(s.begin(), s.end());

        while(i<n){
                while(i< n && s[i]!= ' '){
                    s[r++]=s[i++];
                }
                //space mila
                if(l<r){
                    reverse(s.begin()+l, s.begin()+r);
                    
                    s[r]=' ';
                    r++;
                    l=r;

                }
                i++;
        }

        return s.substr(0, r - 1);
    }
};