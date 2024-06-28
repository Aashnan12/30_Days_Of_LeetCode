class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> freq(n+1,0);

        for(auto &arr : roads){
            freq[arr[0]]++;
            freq[arr[1]]++;
        }

        vector<pair<int,int>> mapping;
        
        for(int i=0;i<n;i++){
            mapping.push_back({freq[i],i});
        }

        sort(mapping.begin(),mapping.end(),greater());

        vector<int> res(n+1,0);
        for(int i=0;i<n;i++){
            int idx = mapping[i].second;
            res[idx] = n-i;
        }

        long long ans = 0;
        for(auto &arr : roads){
            ans += res[arr[0]] + res[arr[1]];
        }
        return ans;
    }
};