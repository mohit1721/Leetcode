class Solution {
public:
    bool isValid(string& s) {
        stack<char>st;
        int n= s.length();
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            //agar openening ( ,,push
            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else{
                // closing....nutralize it
                if(!st.empty()){
                char onTop= st.top();

                if(ch == ')' && onTop =='(' )
                    st.pop();
                else if(ch == '}' && onTop =='{' )
                    st.pop();
                else if(ch == ']' && onTop =='[' )
                    st.pop();
                else
                    // not nutralized ...so not valid parentheses
                    return false;

           }
           else////still empty stack..no opening brack..
            {
                
                return false;
            }
           }


        }
return st.empty();

    }
};