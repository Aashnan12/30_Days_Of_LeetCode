class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;

        int i = 0;
        while(i < intervals.size()){
            if(result.empty() || result.back()[1] < intervals[i][0]){
                result.push_back(intervals[i]);
            }
            else{
                result.back()[1] = max(result.back()[1],intervals[i][1]);
            }
            i++;
        }
        return result;
    }
};