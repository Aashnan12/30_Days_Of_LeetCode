class Solution {
public:
    int t[2501][2501];
    int solve(int idx,int prev_idx,vector<int>& nums){
        if(idx >= nums.size()){
            return 0;
        }

        if(prev_idx != -1 && t[idx][prev_idx] != -1){
            return t[idx][prev_idx];
        }

        
        int take = 0,skip = 0;

        //take
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
            take = 1 + solve(idx+1,idx,nums);
        }

        //skip
        skip = solve(idx+1,prev_idx,nums);

        if(prev_idx != -1){
            t[idx][prev_idx] = max(take,skip);
        }

        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n == 0 || n == 1) return n;

        memset(t,-1,sizeof(t));
        return solve(0,-1,nums);
    }
};