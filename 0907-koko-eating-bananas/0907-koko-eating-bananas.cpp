class Solution {
public:
   long long int calculateHrs(vector<int>& piles, int currSpeedK){
      long long int hours = 0;

        for(int &pile : piles){
            // hours +=  pile / currSpeedK;
            // if(pile%currSpeedK != 0 )
            //  hours++;//if a single banana/half/decimal, remains for a pile, an extra hour will be count !! [basically ceil part]

    // #2
    hours+= ceil((double)pile/currSpeedK);

        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxBanana = *max_element(piles.begin() , piles.end());

        int s=1, e=maxBanana;
        int ans = maxBanana;
        while(s<=e){
            int currSpeedK = s + (e-s)/2 ; //mid
           long long int requiredHrs = calculateHrs(piles, currSpeedK);

            if(requiredHrs <= (long long )h){//matlab ki, abhi currSpeed ko kam krne ki zaroorat h, but can be possible ans*** so store it
            ans = currSpeedK;
            e = currSpeedK - 1;
            }
            else{ //need to increase speed
            s = currSpeedK + 1;
            }

            
        }

        return ans;//lowest speed , jisme she can finish all piles of bananas

    }
};
 