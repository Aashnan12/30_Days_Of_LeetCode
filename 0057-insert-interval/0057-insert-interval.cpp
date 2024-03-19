class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& nums) {
        
        // Push Intervals Lesser than starting of newInterval
        vector<vector<int>> result;
        int n = arr.size();
        int i = 0;
        while(i<n && arr[i][1] < nums[0]){
            result.push_back(arr[i]);
            i++;
        }
        
        // Merge Intervals
        while(i<n && arr[i][0] <= nums[1]){
            nums[0] = min(arr[i][0],nums[0]);
            nums[1] = max(arr[i][1],nums[1]);
            i++;
        }
        result.push_back(nums);

        // Now Push_back rest of intervals

        while(i<n){
            result.push_back(arr[i]);
            i++;
        }
        return result;
    }
};