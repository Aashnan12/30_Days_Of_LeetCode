class Solution {
public:
    int numberOfSubstrings(string s) {
        // vector<int> lastseen(3,-1);
        // int cnt = 0;
        // for(int i=0;i<s.size();i++){
        //     lastseen[s[i] - 'a'] = i;
        //     if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
        //         cnt = cnt + (1 + min(lastseen[0],min(lastseen[1],lastseen[2])));
        //     }
        // }
        // return cnt;

        int left = 0;
        int n = s.size();
        int right = 0;
        unordered_map<char,int> mp;
        int cnt = 0;
        while(right < n){
            mp[s[right]]++;
            while(mp.size() == 3){
                cnt += n - right;
                mp[s[left]]--;
                if(mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }
            right++;
        }
        return cnt;
    }
};