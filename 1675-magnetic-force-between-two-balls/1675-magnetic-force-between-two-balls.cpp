class Solution {
public:
    // same as Aggresise cows

    bool possibleToPlace(int& force, vector<int>& position, int m) {
        int ballCount=1;
        int prev=position[0];
        for(int i=1;i<position.size();i++)
        {
            int curr= position[i];
            if(curr-prev>= force)
            {
                // good, cows/magnet rkh skte h
                // can place balls
                ballCount++;
                // update prev
                prev = curr;

            }
             if(ballCount==m) return true; //early return
        }
         
         return ballCount==m;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(begin(position), end(position));

        int minForce = 1;
        int maxForce = position[n - 1] -
                       position[0]; // maximum distance to ye ho skta h ki dono
                                    // ko ekdnm end points p rkho..
        int result = 0;
        while (minForce <= maxForce) {
            int midForce = minForce + (maxForce - minForce) / 2;

            if (possibleToPlace(midForce, position, m)) {
                result = midForce;
                minForce = midForce + 1; // maximizing ans*
            } else {
                maxForce = midForce - 1;
            }
        }

        return result;
    }
};