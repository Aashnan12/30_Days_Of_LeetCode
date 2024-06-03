class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int hash[26] = {0};
        int count,maxi=INT_MIN;
        for(char& ch : tasks){
            hash[ch - 'A']++;
            maxi = max(maxi,hash[ch-'A']);
        }
        count = (maxi-1)*(n+1);
        for(int i=0;i<26;i++){
            if(hash[i] == maxi){
                count++;
            }
        }
        return max(count,(int)tasks.size());
    }
};