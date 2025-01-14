class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        
    
        unordered_map<int,int>freq;

        vector<int>ans(n,0);
        int commonCount=0;
        for(int i=0;i<n;i++)
        {

            freq[A[i]]++;
            if(freq[A[i]]==2 )
                commonCount++;
                
            freq[B[i]]++;
            if(freq[B[i]]==2)
                commonCount++;
 

    ans[i]=commonCount;
        }

return ans;



    }
};