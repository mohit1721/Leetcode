class Solution {
public:
int dp[1001];
int M=1e9+7;
int solve(int n){
    if(n==1 || n==2 ) return n;
    if(n==3) return 5;
if(dp[n] !=-1 ) return dp[n];
    return dp[n] =(2*solve(n-1)% M + solve(n-3) %M)%M ;  
}
    int numTilings(int n) {
        memset(dp,-1, sizeof(dp));

return solve(n);


    }
};