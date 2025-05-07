class Solution {
public:
    bool binarySearch(vector<int>& nums, int& target) {
        int s = 0, e = nums.size();
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (target == nums[mid]) {
                return true;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        int l=0, h = m*n - 1;
        while(l<=h){
            int mid = l + (h-l) /2;
            int row = mid/m;
            int col = mid% m;

            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]  < target ){
                l = mid  + 1;
            }
            else{
                h = mid - 1;
            }
        }

      
        return false;
    }
};