class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int hash[26] = {0};
        
        int n = words.size();
        string str = words[0];

        for(char& ch : str){
            hash[ch - 'a']++;
        }

        for(int i=1;i<n;i++){
            int freq[26] = {0};
            string temp = words[i];
            
            for(char& ch : temp){
                freq[ch - 'a']++;
            }

            for(int i=0;i<26;i++){
                hash[i] = min(hash[i],freq[i]);
            }
        }

        vector<string> ans;
        for(int i=0;i<26;i++){
            while(hash[i] > 0){
                char ch = 'a' + i;
                string str(1,ch);
                ans.push_back(str);
                --hash[i];
            }
        }

        return ans;
    }
};