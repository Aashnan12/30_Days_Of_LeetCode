class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles < numExchange) return numBottles;
        int res = numBottles,full = 0,empty = numBottles;
        while(empty >= numExchange){
            full = (empty / numExchange);
            res += full;
            empty = full + (empty % numExchange);
        }
        return res;
    }
};