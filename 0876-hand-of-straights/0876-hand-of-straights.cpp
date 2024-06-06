class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;

        map<int,int> mp;

        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }

        while(!mp.empty()){
            int curr = mp.begin()->first;
            int count = 0;
            while(count < groupSize){
                if(mp.find(curr+count) == mp.end()){
                    return false;
                }
                mp[curr + count]--;
                if(mp[curr + count] <= 0){
                    mp.erase(curr + count);
                }
                count++;
            }
        }
        return true;
    }
};