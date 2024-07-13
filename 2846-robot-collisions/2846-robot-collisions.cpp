class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> index(n);
        
        // Initialize the index vector
        for (int i = 0; i < n; ++i) {
            index[i] = i; 
        }

        // Sort indices based on the positions of the robots
        sort(index.begin(), index.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            int curridx = index[i];
            int currhealth = healths[curridx];
            char currdir = directions[curridx];

            while(!stk.empty() && currhealth > 0 && directions[stk.top()] == 'R' && currdir == 'L') {
                int previdx = stk.top();
                int prevhealth = healths[previdx];

                if (prevhealth == currhealth) {
                    stk.pop();
                    healths[previdx] = 0;
                    healths[curridx] = 0;
                    currhealth = 0;
                } else if (prevhealth < currhealth) {
                    stk.pop();
                    healths[previdx] = 0;
                    currhealth -= 1;
                    healths[curridx] = currhealth;
                } else {
                    healths[previdx] -= 1;
                    currhealth = 0;
                    healths[curridx] = 0;
                }
            }

            if (currhealth > 0) {
                stk.push(curridx);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};
