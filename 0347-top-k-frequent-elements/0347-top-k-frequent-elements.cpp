class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> map;
        for(int &i : nums){
            map[i]++;
        }

        for(auto i : map){
            pq.push({i.second,i.first});
        }

        vector<int> ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};