class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n=prices.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            //our condition satisfies
            while(!st.empty() && prices[st.top()] >= prices[i])
            {
                int idx = st.top();
                st.pop();
                prices[idx] -= prices[i];
            }
            //else
            st.push(i);
             


        }
        
        return prices;

    }
};