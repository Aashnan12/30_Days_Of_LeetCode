//Optimal approach
class Solution {
public:
    #define ll long long
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<ll,ll> map1,map2;

        ll maxi = *max_element(nums1.begin(),nums1.end());

        for(int &it : nums1){
            map1[it]++;
        }
        for(int &it : nums2){
            map2[it]++;
        }

        long long ans = 0;

        for(auto &[key,freq] : map2){
            ll b = key * k;
            ll d = b;
            while(b <= maxi){
                ans += freq * map1[b];
                b += d;
            }
        }
        return ans;
    }
};








// TLE with optimised precomputation.
// class Solution {
// public:
//     long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
//         unordered_map<long long ,long long> map;
//         for(auto &it : nums1){
//             map[it]++;
//         }

//         long long count = 0;
//         for(auto &it : nums2){
//             long long target = it * k;
//             for(auto &[key,val] : map){
//                 if(key % target == 0){
//                     count += val;
//                 }
//             }
//         }
//         return count;
//     }
// };