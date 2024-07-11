class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        bool flip = false;

        for(int i=0;i<n;i++){
            int curr = flip ? !nums[i] : nums[i];
            if(curr == 0){
                ans++;
                flip = !flip;
            }
        }
        return ans;
    }
};