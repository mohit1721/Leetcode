class Solution {
public:
    int numberOfSubstrings(string &s) {
    int n=s.length();
    int res=0;
    vector<int>mp(3,0); //0-a, 1-b, 2-c
    int i=0,j=0;
    while(j<n){
        char ch = s[j];
        mp[ch-'a']++;
    // if(mp[0] > 0 && mp[1]> 0 && mp[2] > 0){
    //     res+= (n-j); 
    // mp[s[i]- 'a']--;
    // i++;  
    // }
    // why not if ?? and while->
    // dry run aabcabc 
    // since, for the aabc part -> there will be 4 substrings from the first a[i at 0th index] , then shrinking i to 1st index,since still freq of a,b,c >=1 , then again add (n-j) to res, as again 4 substrings from a at 1st index..

// if case -> aaabc -> only 1 would ans-> which is wrong-..it is just considering once and that from i=0 to i=4 ....then i and j both increases .. missing the left substrinfs from i=1 and i=2 indexes... 
    // 
    while(mp[0]>0 && mp[1]>0 && mp[2]>0){
        res+=(n-j);
        // shrink and still check the freq.s
        mp[s[i] - 'a']--;
        i++;
    }



j++;


    }        


return res;


    }
};