class Solution {
public:
    int tabLCS(string &a, string &b){
        int n=a.length();
        int m=b.length();
        int ans=0;
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
       for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (a[i] == b[j]) {
                    ans = 1 + dp[i + 1][j + 1];
                } else {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0]; 
    }
 

    int longestPalindromeSubseq(string& s) {
       string t = s;
       reverse(t.begin(), t.end());

       return tabLCS(s,t); 




    }
};