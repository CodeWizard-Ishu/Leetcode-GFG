class Solution {
public:
    int helper(vector<vector<int>>&v,int idx,vector<int>&dp) {
        if (idx==v.size())
            return 0;
        if (dp[idx]!=-1)
            return dp[idx];
        int nottake=helper(v,idx+1,dp);
        int take=v[idx][2]+helper(v,(lower_bound(v.begin(),v.end(),vector<int>{v[idx][1],0,0})-v.begin()),dp);
        return dp[idx]=max(take,nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>v(n,vector<int>(3));
        for (int i=0;i<n;i++)
            v[i]={startTime[i],endTime[i],profit[i]};
        sort(v.begin(),v.end());
        vector<int>dp(n,-1);
        return helper(v,0,dp);
    }
};