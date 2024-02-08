class Solution {
public:
    int solve(int n, vector<int>& dp)
    {
        if(n == 0)
            return 0;

        if(dp[n] != -1)
            return dp[n];

        int mini = INT_MAX;
        for(int i=1; i*i<=n; i++)
        {
            int perfectSquare = i*i;
            int ans = 1 + solve(n - perfectSquare, dp);
            mini = min(mini,ans);
        }

        dp[n] = mini;
        return dp[n];
    }

    int numSquares(int n)
    {
        vector<int> dp(n+1,-1);
        return solve(n, dp);
    }
};