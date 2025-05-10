class Solution {
public:
    int mem(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
         if(i>=a.length() || j>=b.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

         int ans = 0;

          if(a[i]==b[j]){
            ans = 1 + dp[i+1][j+1];
         }else{
            ans = max(mem(a,b,i+1, j,dp) , mem(a,b,i,j+1,dp));
         }

         return dp[i][j]= ans;

    }
 
    int tab(string& a, string& b){
         vector<vector<int>> dp(a.length() + 1,  vector<int>(b.length() + 1, 0));
        int n=a.length();
        int m=b.length();
        int ans=0;
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){

          if(a[i]==b[j]){
            ans = 1 + dp[i+1][j+1];
         }else{
            ans = max(dp[i+1][j],dp[i][j+1]);
         }

         dp[i][j]= ans;


                }
            }
return dp[0][0];
    }

    int longestCommonSubsequence(string& text1, string& text2) {
        // vector<vector<int>> dp(text1.length() + 1,vector<int>(text2.length() + 1, -1));

        // return mem(text1, text2, 0, 0, dp);

        return tab(text1, text2);
    }
};