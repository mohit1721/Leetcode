class Solution {
public:
    
string longestPalindrome(string &s) {
    int n = s.length();
    if (n == 0) return "";

    vector<vector<bool>> dp(n, vector<bool>(n, false)); 
    int start = 0, maxLen = 1;

    // Every single character is a palindrome
    for (int i = 0; i < n; i++) dp[i][i] = true;

    // Check two-character substrings
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Check substrings of length 3 or more
    for (int len = 3; len <= n; len++) {  // Length of substring
        for (int i = 0; i <= n - len; i++) {  // Start index
            int j = i + len - 1;  // End index

            if (s[i] == s[j] && dp[i + 1][j - 1]) { // Expand inward
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }

    return s.substr(start, maxLen);
}

};