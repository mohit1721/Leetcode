class Solution {
public:
bool helper(int start,int n,vector<int>& derived )
{
             vector<int> org(n);
    org[0] = start;

    // Compute the rest of the original array
    for (int i = 1; i < n; ++i) {
        org[i] = org[i - 1] ^ derived[i - 1];
    }

    // Check the circular condition
    return (org[n - 1] ^ org[0]) == derived[n - 1];

}
    bool doesValidArrayExist(vector<int>& derived) {

        int n=derived.size();

      return(helper(0,n,derived) || helper(1,n,derived));


    }
};