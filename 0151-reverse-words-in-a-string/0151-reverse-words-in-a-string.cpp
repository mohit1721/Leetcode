class Solution {
public:
    string reverseWords(string& s) {
        //
 // A. Reverse whole String s
// jb tk character milta h assign to r
 // else,agar space milta h to,reverse the word b.w l & r
//  r ko v to aage badhao** gltiii
// l ko v to ab aage badhana h ..jo ki ab r k paas ayega
 // return only r-1

        int n = s.length();
        int i = 0;
        // A. Reverse
        reverse(s.begin(), s.end());
        // 
        int l=0, r=0;
        while(i<n)
        {
            while(i<n && s[i] != ' ')//jbtk space n mile
            {
                s[r++]= s[i++];
            }
         //else,agar space milta h to,reverse the word b.w l & r

            if(l<r)
            {
        // reverse this word now
            reverse(s.begin()+l, s.begin()+r); //l to r
            // last m ek space add
            s[r]=' ';
            r++;
            l=r; //l ko aage badha do
            }
    i++;



        }

return s.substr(0, r-1);//last space exclue;




    }
};