class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        int mini = INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<4;i++){
            mini = min(mini,nums[n-1-3+i] - nums[i]);
        }

        return mini;
    }
};