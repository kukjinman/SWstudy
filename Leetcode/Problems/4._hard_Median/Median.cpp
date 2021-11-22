class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {

        double ret;
        vector<int> v1 = nums1;

        for (int i = 0; i < nums2.size(); i++) {
            v1.push_back(nums2.at(i));
        }

        return ret;
    }
};