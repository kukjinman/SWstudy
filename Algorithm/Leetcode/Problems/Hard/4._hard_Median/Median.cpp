class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ret;
        vector<int> v1 = nums1;
        
        for(int i = 0; i < nums2.size(); i++)
        {
            v1.push_back(nums2.at(i));
        }
        
        sort(v1.begin(), v1.end());
        
        
        cout << " size : " << v1.size()/2 << endl;
        if(v1.size() %2 != 0)
        {
            ret = v1[v1.size()/2];

        }
        else
        {
            cout << " val : " << double(v1[v1.size() / 2] + v1[(v1.size() -1) / 2]) << endl;
            
            cout << " val /2 : " << double(v1[v1.size() / 2] + v1[(v1.size() -1) / 2]) / 2 << endl;
            ret = double(v1[v1.size() / 2] + v1[(v1.size() -1) / 2]) / 2;
        }
        
        
        return ret;
    }
};