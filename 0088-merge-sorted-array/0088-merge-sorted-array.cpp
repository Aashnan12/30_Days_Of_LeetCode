class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,idx=0;
        vector<int> sorted(m+n);
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                sorted[idx++] = nums1[i++];
            }
            else{
                sorted[idx++] = nums2[j++];
            }
        }
        while(i<m){
            sorted[idx++] = nums1[i++];
        }
        while(j<n){
            sorted[idx++] = nums2[j++];
        }
        nums1 = sorted;
    }
};