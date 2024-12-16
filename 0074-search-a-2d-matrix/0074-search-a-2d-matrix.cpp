class Solution {
public:
    bool binarySearch(vector<int>& nums, int& target)
    {
        int s = 0, e= nums.size();
        while(s<=e)
        {
            int mid = s+ ( e - s) /2;
            if(target == nums[mid])
            {
                return true;
            }
            else if (nums[mid] < target)
            {
                s= mid+1;
            }
            else{
                e = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++)
        {
            if(target >= matrix[i][0] && target <= matrix[i][m-1])  //*
            {
                return binarySearch(matrix[i] , target);
            }
            // else

        }
return false;
        
    }
};