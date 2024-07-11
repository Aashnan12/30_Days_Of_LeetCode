class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0,n = nums.size(),i;
        for(i=0;i <= n-3;i++){
            if(nums[i] == 0){
                ans++;
                nums[i] = 1;
                nums[i+1] = nums[i+1]==0?1:0;
                nums[i+2] = nums[i+2]==0?1:0;
            }
        }
        if(nums[n-1] == 0) return -1;
        if(nums[n-2] == 0) return -1;
        
        return ans;
    }
};