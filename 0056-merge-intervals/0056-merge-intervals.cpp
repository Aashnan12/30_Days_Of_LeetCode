class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 1;
        int n = intervals.size();
        vector<vector<int>> result;
        if(n==0)return result;
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);
        int j=0;
        while(i<n){
            if(result[j][1] >= intervals[i][0]){
                result[j][1] = max(result[j][1],intervals[i][1]);
            }
            else{
                j++;
                result.push_back(intervals[i]);
            }
            i++;
        }
        return result;
    }
};