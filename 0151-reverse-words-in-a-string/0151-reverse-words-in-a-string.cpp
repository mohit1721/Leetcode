class Solution {
public:
    string reverseWords(string s) {
        //
        int n=s.length();
        int i=0;
        int l=0,r=0;
//A. Reverse whole String s
reverse(s.begin(),s.end());


        while(i<n)
        {
            //B.
            while(i<n && s[i] != ' ')//jb tk character milta h assign to r
            {
                s[r++]=s[i++];
            }
            //else,agar space milta h to,reverse the word b.w l & r
            if(l<r)
            {
                reverse(s.begin()+l, s.begin()+r);//**
                //ek space add to at last
                s[r]=' ';
                r++;//r ko v to aage badhao** gltiii
                //l ko v to ab aage badhana h ..jo ki ab r k paas ayega
                l=r;//

            }
            //





            i++;
        }

//return only r-1 
s=s.substr(0,r-1);
return s;


    }
};