class Solution {
public:
bool canDistribute(vector<int>& candies, long long candiesToDistribute, long long children){
    int n = candies.size();

    for(int i=0;i<n;i++)
    {
        children -= candies[i] / candiesToDistribute;
        if(children<=0) return true; //early return
    }
    return children<=0; //after complete iterate..in wrost case 
}
    int maximumCandies(vector<int>& candies, long long children) {
     // brute force
     int n=candies.size();

     long long totalCandies=0;
     int maximumCandies=0;
     for(int i=0;i<n;i++){
        totalCandies+=candies[i];
        maximumCandies = max(maximumCandies, candies[i]);
     }
    //  
    if(totalCandies< children) return 0; //
    // brute force 
    // for(int candiesToDistribute=maximumCandies; candiesToDistribute>=1;candiesToDistribute--)
    // {
    //     long long childrenSatisfied=0;//

    //     // ab candies ko iterate kro*** mistake++
    //     for(int i=0;i<n;i++)
    //     {
    //          childrenSatisfied += candies[i] / candiesToDistribute;//current pile se itne children ko satisfy kr skte h...agar currently itne[candiesToDistribute] candies ho...
            
    //     }
    //     // agar itne candies[candiesToDistribute] ( outer loop..) se sb children ka ho gya to return
    //         if(childrenSatisfied>=children) return candiesToDistribute;

    // }
// else
// return 0;

// using Binary Search

int s=1;
int e=maximumCandies;
int result=0;
while(s<=e)
{
    long long candiesToDistribute= s + (e-s)/2; //mid
    if(canDistribute(candies,candiesToDistribute , children )){
        // store the current ans and maximize
        result = candiesToDistribute;
        // try to more maximze
        s = candiesToDistribute + 1; //mid + 1
    }
    else{
        //
        e = candiesToDistribute - 1;//find to satisfy
    }
}

return result;


    }
};