class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        int n = s.length();
     
        while (1) {
   bool digitFound=false;
            for (int i = 0; i < s.length(); i++) {

                
                    if (isdigit(s[i]))
                       { 
                        for (int j = i - 1; j >=0; j--) {

                    if(isalpha(s[j]))
                    {
                        //erase
                        s.erase(i,1);
                        s.erase(j,1);
                        digitFound=true;
                        break;
                    }
                        }
                        break;//stop  ...ek baar m ek hi baar remove
                }
            }
            if(digitFound==false)
            break;
            
        }

        return s;
    }
};