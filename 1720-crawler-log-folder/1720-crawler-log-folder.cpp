class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(auto log : logs){
            if(log == "../" && cnt > 0){
                cnt--;
            }
            else if(log != "../" && log != "./"){
                cnt++;
            }
        }

        return cnt;
    }
};