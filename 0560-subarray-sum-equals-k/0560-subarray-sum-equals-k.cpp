class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
//         int cnt=0;
//         for(int i=0;i<nums.size();i++){
//             int sum=0;
//             for(int j=i;j<nums.size();j++){
//                     sum+=nums[j];
//                 if(sum==k){
//                     cnt++;
//                 }
            
//             }
            
//         }
// return cnt;

    // #2. using map [gain method] O(n)

    unordered_map<int,int>mp;
    int sum=0;
    int cnt=0;
    //phle se 0 k liye 1 ka mapping ..jo obvivous hoga..sum 0 ka freq 1 hoga hi
    mp[0]=1;

    for(int i=0;i<=nums.size()-1;i++)
    {
        sum+=nums[i];
        //ab map m iss sum k corresponding sum-k ...krke map m chk kro..agar milta h to cnt ++..
        if(mp.count(sum-k)) // Yeh condition check karta hai ki agar (sum - k) map mein already hai ya nahi.
        {
            // Agar (sum - k) map mein hai, toh hum count ko increase karte hain us frequency se.

            cnt+=mp[sum-k];//sum-k hmesa 0 nhi hoga..1st time hoga..uske liye 0->1 ka map phle se krke rkhe 
        
         }
        //   Har iteration ke baad, hum sum ka frequency map mein increase karte hain.
        mp[sum]++; //achha map m fir cummSum ka freq ko 1/++ krna pdega n..for next iteration/traverse

    }
    return cnt;

    }
    
};