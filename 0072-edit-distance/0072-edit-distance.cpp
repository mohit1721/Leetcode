class Solution {
public:
    int solve(string &a, string &b, int i, int j,vector<vector<int>>&dp)
    {
        int ans=0;
        //BC
        // 
        if(i>=a.length()) return b.length() - j ;

        if(j>=b.length()) return a.length()- i; ///jitna bacha dusra m  wo ans

    if(dp[i][j] != -1) return dp[i][j];

    if(a[i]==b[j])
    {
        ans = 0 + solve(a,b,i+1,j+1,dp);
    }
    else{
        int Replace  = 1  + solve(a,b,i+1,j+1,dp);

        int Insert = 1 + solve(a,b,i, j+1,dp);///
        int Delete = 1  + solve(a,b,i+1,j,dp); ////delete krna means, aage badhna***simple CS...jisse delete kr rhe h usi ka index ko aage badha dena h
        ans = min ({Replace,Insert,Delete});
    }
      
        return dp[i][j] = ans;
    }

    // tab]
    int tab(string &a, string& b)
    {
        int n=a.length();
        int m=b.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    // #BASE CASE HANDLE

//  if(i>=a.length()) return b.length() - j ;
for(int j=0;j<=m;j++){
    dp[n][j] = m-j;
}
        // if(j>=b.length()) return a.length()- i; ///jitna bacha dusra m  wo ans
for(int i=0;i<=n;i++){
    dp[i][m] = n-i;
}
// 

for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){

        if(a[i]==b[j]){
            dp[i][j] = 0 + dp[i+1][j+1];
        }else{
                int replace = 1 + dp[i+1][j+1];
                int del = 1 + dp[i+1][j];
                int insert = 1 + dp[i][j+1];
                dp[i][j] = min({replace, del , insert});
        }


    }
}

return dp[0][0];



    }

    int minDistance(string &word1, string& word2) {
        // int n=word1.length();
        // int m=word2.length();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // return solve(word1,word2,0,0,dp);

return tab(word1, word2);


    }
};