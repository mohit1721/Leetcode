class Solution {
public:
    vector<vector<int>> res;
    int n;
    void solve(int idx, vector<int>& candidates, int target, int currSum,
               vector<int>& temp) {
                if(currSum==target)
                {
                    res.push_back(temp);
                    return;
                }
                if( currSum>target ||idx>=n )
                    return;
                
                //DO
                currSum+=candidates[idx];
                temp.push_back(candidates[idx]);

                // Explore... []not idx+1....** qki same number repeatedly le skte h***
            solve(idx, candidates, target, currSum,temp);

            //UNDO
            currSum-=candidates[idx];
            temp.pop_back();
            // REXPLORE
            solve(idx+1, candidates, target, currSum,temp);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        n = candidates.size();
        solve(0, candidates, target, 0, temp);

        return res;
    }
};