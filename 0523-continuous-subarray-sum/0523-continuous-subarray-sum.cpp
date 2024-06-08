class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> map;
        int sum = 0,store = 0;
        map.insert({0,-1}); // Edge Case kisi point pr zero ho jara h means 0 se i length ki subarray mili h.

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            store = sum % k;
            if(map.find(store) == map.end()){
                map.insert({store,i});
                continue;
            }
            if((i - map[store]) > 1){
                return true;
            }
        }

        return false;
    }
};