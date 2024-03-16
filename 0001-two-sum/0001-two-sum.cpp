class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //Method 1 -> O(n^2)

        // int n= nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {-1,-1};

        //Method 1 -> O(n*logn)

        unordered_map<int,int> map;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = target - nums[i];
            if(map.find(num) != map.end()){
                return {map[num],i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};