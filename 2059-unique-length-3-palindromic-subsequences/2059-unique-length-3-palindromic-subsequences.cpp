class Solution {
public:


    int countPalindromicSubsequence(string s) {
      int n=s.length();
      unordered_set<char>uniqueLetters;
      for(int i=0;i<n;i++)
      {
        uniqueLetters.insert(s[i]);
      }
      int result=0;
      for(char letter: uniqueLetters){
        int leftIdx = -1;
        int rightIdx = -1;
        for(int i=0;i<n;i++){
            if(s[i]==letter)
            {
                if(leftIdx == -1)//pehla
                {
                    leftIdx = i;
                }
                //right wla always update
                rightIdx = i;
            }
        }

    unordered_set<char>st;
    for(int mid = leftIdx+1;mid<=rightIdx-1 ;mid++){
        st.insert(s[mid]);
    }
result+=st.size();


      }

return result;
    }
};