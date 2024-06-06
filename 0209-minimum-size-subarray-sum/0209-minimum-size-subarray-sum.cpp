#pragma GCC optimize("O3", "unroll-loops")
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;
        int i=0;
        int j = 0;
        int sum = 0;
        int n = nums.size();
        while(j<n){
            sum += nums[j];
            while(i<=j && sum >= target){
                mini = min(mini,j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return mini==INT_MAX?0:mini;
    }
};