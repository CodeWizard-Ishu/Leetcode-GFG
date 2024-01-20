class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curHold = INT_MIN, curNotHold = 0;
        for (const int stockPrice : prices) {
            int prevHold = curHold, prevNotHold = curNotHold;
            curHold = max(prevHold, prevNotHold - stockPrice);
            curNotHold = max(prevNotHold, prevHold + stockPrice);
        }
        return curNotHold;
    }
};