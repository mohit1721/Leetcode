class Solution {
public:
int n;
vector<vector<int>>result;
void solve(int idx,vector<int>& candidates,int target,vector<int>& temp )
{
 if(target<0 ) return;
  if( target==0){
    result.push_back(temp);
    return;
  }
  

  //****
  for(int i=idx;i<n;i++)///i=idx
  {
  if(i > idx && candidates[i]==candidates[i-1]) continue;//***

    //do
    temp.push_back(candidates[i]);
      //explore
     //i+1-->idx
    solve(i+1,candidates,target-candidates[i],temp);
    //undo
    temp.pop_back();


  }
 

}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin(),candidates.end());//**
        vector<int> temp;
        solve(0,candidates,target,temp);
        return result;
    }
};