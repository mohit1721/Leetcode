class Solution {
public:
/*
✔ Soch badlo, approach easy ho jayegi!
✔ Instead of picking K cards, find N-K cards to discard!
✔ Sliding Window efficiently finds the minimum window to remove.
✔ Code is simple, no extra space needed.
// */
// exact my fixed sliding window template 
    int maxScore(vector<int>& cards, int k) {
          int n = cards.size();
          int totalSum = 0;
        for(int num: cards)
        {
            totalSum+=num;
        }
        // edge case
        if(k==n) return totalSum; 

        int windowSizeToDiscard = n-k;
        int left=0, right=0;
        int minSumToDiscard=INT_MAX;//
        int currentWindowSum = 0;
        while(right<n)
        {
            //
            if((right-left+1) < windowSizeToDiscard)//**
            {
                currentWindowSum +=cards[right];
                right++;
            }
            else{
                //>= W-size
                // add the current element
                currentWindowSum  += cards[right];
                // slide form left
                // calculate the minSumToDiscard
                
            minSumToDiscard = min(minSumToDiscard, currentWindowSum );
                currentWindowSum -= cards[left];
                left++;
                // right ko v aage badhao
                right++;

            }
        }
        
        return (totalSum - minSumToDiscard);
    }
};