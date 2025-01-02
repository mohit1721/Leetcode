class Solution {
public:
bool isVowel(char &x)
{
    if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
        return true;

    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int nq= queries.size();
        vector<int>suffixCnt(words.size()+1);
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<words.size();i++)
        {
                
                // int x=words[i].length();
                if( isVowel(words[i][0]) && isVowel(words[i].back())){
                suffixCnt[i+1]=suffixCnt[i] + 1;
                }else{
                    suffixCnt[i+1]=suffixCnt[i];//store the prev cnt.
                }

        }
        for(int i=0;i<nq;i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            int result = suffixCnt[r+1] - suffixCnt[l];
            ans.push_back(result);
        }
        return ans;
    }
};