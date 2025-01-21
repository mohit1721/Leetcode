class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int &num : nums)
        {
            mp[num]++;
        }
    priority_queue<pair<int,int>>maxHeap;
    for(auto &ele: mp)
    {
        maxHeap.push({ele.second, ele.first});
    }
    vector<int>res;
    while(k--)
    {
        int maxFreqEle = maxHeap.top().second;
        maxHeap.pop();
        res.push_back(maxFreqEle);

    }
return res;


    }
};