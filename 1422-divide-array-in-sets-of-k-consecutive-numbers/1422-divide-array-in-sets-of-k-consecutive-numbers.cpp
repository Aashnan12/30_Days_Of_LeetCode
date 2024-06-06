class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k) return false;

        map<int,int> map;
        for(int &num : nums){
            map[num]++;
        }

        while(!map.empty()){
            int curr = map.begin()->first;

            for(int i=0;i<k;i++){
                if(map.find(curr + i) == map.end()){
                    return false;
                }

                map[curr + i]--;
                if(map[curr+i] < 1){
                    map.erase(curr+i);
                }
            }
        }

        return true;
    }
};