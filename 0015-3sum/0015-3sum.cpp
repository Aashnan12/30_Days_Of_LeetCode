class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> set;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            int j = i+1;
            int k = nums.size()-1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    set.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto it : set){
            ans.push_back(it);
        }
        return ans;

    }
};