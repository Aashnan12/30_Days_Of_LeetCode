class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr(m+n,0);

        int index = 0,i=0,j=0;
        
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                arr[index++] = nums1[i++];
            }
            else{
                arr[index++] = nums2[j++];
            }
        }
        while(i<m){
            arr[index++] = nums1[i++];
        }
        while(j<n){
            arr[index++] = nums2[j++];
        }

        nums1 = arr;
    }
};