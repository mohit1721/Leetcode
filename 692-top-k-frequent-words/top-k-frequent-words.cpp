class Solution {
public:
// for sort** [fxn based custom comp]
    //  bool myComp(pair<int,string>&a, pair<int,string>&b){
    //     return a.first==b.first ? (a.second>b.second) : (b.second>a.second);
    // }



     // Custom comparator for min-heap (to get top K frequent words)
    struct myComp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) 
                return a.second > b.second;  // Lexicographical order for same frequency
            return a.first < b.first; // Higher frequency first
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto &word : words){
            mp[word]++;
        }
        vector<string>ans;
   
  
    // priority_queue<pair<int,string> , vector<pair<int,string>> , greater<int>>minHeap;
    priority_queue<pair<int,string>, vector<pair<int,string>> , myComp >maxHeap;
    for(auto &it: mp)
    {
        maxHeap.push({it.second , it.first});
    }
    while(k && !maxHeap.empty())
    {
        if(k==0) break;
        auto temp = maxHeap.top();
        maxHeap.pop();
        string topFreq = temp.second;
        ans.push_back(topFreq);
        k--;
    }
        return ans;
    }
};