class Solution {
public:
    int heightChecker(vector<int>& arr) {
        vector<int> nums = arr;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] != nums[i]){
                ans++;
            }
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();