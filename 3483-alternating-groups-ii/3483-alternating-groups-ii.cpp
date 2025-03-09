class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& clrs, int k) {
        int n=clrs.size();
        // NOTE- Circular Array - append the same array [length acc. to q. -> like in this -> k-1 length]
        for(int i=0;i<k-1;i++)
        {
            clrs.push_back(clrs[i]);
        }
        //  sw
        int res = 0;
        int s=0, e=1;
        int windowLen=1;

        while(e<n+k-1){
            // window length < k
        if(clrs[e]==clrs[e-1]){
            windowLen=1;//restart
            // move left window
            s = e;
        }else{
            // go further
            windowLen++;
        }

            if(windowLen==k){
                res++;
                windowLen--;//shrinking from left side
            }
            // move continue
            e++; // 
        }
    


        return res;
    }
};