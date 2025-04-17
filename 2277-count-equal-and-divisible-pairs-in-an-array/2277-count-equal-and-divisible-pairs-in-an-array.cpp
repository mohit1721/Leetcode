class Solution {
public:
    int countPairs(vector<int>& nums, int k) {

int n=nums.size();
// int count=0;
// for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         if(nums[i]==nums[j] && (i*j)% k ==0) count++;
//     }
// }
// return count;


// #2. O(n + m²) [m-> size of index array in map]
  map<int, vector<int>> mp;
    
    // Step 1: Store all indices where each value occurs
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    int count = 0;

    // Step 2: For each group of same elements, check index pairs
     for(auto&[val,indexes] : mp){
        int sz=indexes.size();
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                if(indexes[i]*indexes[j] % k ==0)
                    count++;
            }
        }
     }

    return count;

    }
};