class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
         set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){

                    if(i==j || j==k || k==i){
                        continue;
                    }
                    // if(digits[k] %2==0){
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                            if(num%2==0 && num >=100 && num <=999)
                        st.insert(num);

                     
                }
            }
        }
         vector<int>ans(st.begin(), st.end());
        // sort(ans.begin(), ans.end());

return ans;
    }
};