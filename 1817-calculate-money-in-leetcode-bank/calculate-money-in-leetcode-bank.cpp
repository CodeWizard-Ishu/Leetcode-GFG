class Solution {
public:
    int totalMoney(int n) {
        int weeks = n/7;
        int money = 0;
        for(int i=1; i<=weeks; i++)
        {
            money = money + 7*(i+3);
        }
        for(int i=7*weeks; i<n; i++)
        {
            money = money + ++weeks;
        }
        return money;
    }
};