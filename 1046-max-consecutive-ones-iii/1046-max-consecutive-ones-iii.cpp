class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zerocount = 0,l = 0, r = 0, n = nums.size(),maxlen = 0;

        while(r < n){
            if(nums[r] == 0){
                zerocount++;
            }

            while(zerocount > k){
                if(nums[l] == 0) {
                    zerocount--;
                }
                l++;
            }

            if(zerocount <= k){
                maxlen = max(maxlen,r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};