// class Solution {
// public:
//     int min_len = 2;
//     bool checkSubarraySum(vector<int>& nums, int k) {
        
//         unordered_map<int,int> map;
//         int sum = 0,store = 0;
//         map[0] = -1; // Edge Case kisi point pr zero ho jara h means 0 se i length ki subarray mili h.

//         for(int i=0;i<nums.size();i++){
//             sum += nums[i];
//             store = sum % k;
//             if(map.find(store) == map.end()){
//                 map[store] = i;
//                 continue;
//             }
//             if((i - map[store]) >= min_len){
//                 return true;
//             }
//         }

//         return false;
//     }
// };









// bhai aaj ka leetcode ka question dekhio zara continuous subarray sum 
// usme yeh solution main ek testcase fail ho rha hai [5,0,0,0] k=3

// yeh code hai check karke bataiyo change kya karun

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m.insert({0,-1});
        int total=0;
        for(int i=0;i<nums.size();i++){
            total=total+nums[i];
            int r=total%k;
            if(m.find(r) == m.end()){
                m.insert({r,i});
                continue;
            }
            if(i-m[r]>1){
                return true;
            }
            
        }
        return false;
    }
};