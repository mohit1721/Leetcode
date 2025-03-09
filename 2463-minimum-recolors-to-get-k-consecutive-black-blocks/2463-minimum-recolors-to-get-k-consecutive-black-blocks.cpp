class Solution {
public:
   int minimumRecolors(string& blocks, int k) {
    int n = blocks.size();
    int low = 0, high = 0, windowSize = k;
    
    int whiteCount = 0, minOperations = INT_MAX;

    while (high < n) {
        //case A :  windowLen < windowSize

        //case A -> i)  always count++
         if(blocks[high] == 'W')
                whiteCount++;
            // ii)
        if(high - low + 1 < windowSize ){
            high++;

        }
        //case B:  else windowLen == windowSize
        else{
            minOperations = min(minOperations, whiteCount);
            // slide left window acc. to qn**
                if(blocks[low] == 'W'){
                     whiteCount--;
                }

            low++;
            // also right window
            high++;
        }
       
    }

    return minOperations;
}

};