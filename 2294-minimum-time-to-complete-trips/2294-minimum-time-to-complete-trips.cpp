class Solution {
public:
// O(nlog(max(time)×totalTrips))
    bool canComplete(vector<int>& time,long long &minTimeToTake, int totalTrips ){
        int n=time.size();
        long long trips=0;
        for(int i=0;i<n;i++)
        {
            trips+=minTimeToTake/time[i]; ///only change**

            if(trips>=totalTrips) return true;
        }
        // 
        return trips>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long maxTime =(long long)*min_element(time.begin(), time.end()) * totalTrips; //chnge*
        long long totalTime=0;
        int n=time.size();
        for(int i=0;i<n;i++)
        {
            totalTime+=time[i];
        }
        long long s=1,e=maxTime;
        long long result=e; //change
        while(s<=e)
        {
            long long minTimeToTake = s + (e-s)/2; //mid
            if(canComplete(time, minTimeToTake,totalTrips))
            {
                // this time , minimum needed...
                // save the current anms
                result= minTimeToTake;
                // ab minimum ki need h to , right ko sarkao
                e = minTimeToTake - 1; //mid-1
            }
            else{
                s = minTimeToTake + 1;
            }
        }
        return result;
    }
};