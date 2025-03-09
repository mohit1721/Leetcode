class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged;
    int i = 0, j = 0;
    // The brute-force approach involves merging the two arrays into one sorted array and then finding the median
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i++]);
        } else {
            merged.push_back(nums2[j++]);
        }
    }
    
    while (i < nums1.size()) merged.push_back(nums1[i++]);
    while (j < nums2.size()) merged.push_back(nums2[j++]);
    
    int n = merged.size();
    return n % 2 == 0 ? (merged[n / 2 - 1] + merged[n / 2]) / 2.0 : merged[n / 2];
}

};