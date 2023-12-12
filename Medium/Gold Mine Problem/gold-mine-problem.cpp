//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
        int n=mat.size();
        int m=mat[0].size();
        
        if(j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int frwd=mat[i][j]+solve(i,j+1,mat,dp);
        int topfrwd=mat[i][j];
        if(i-1>=0)topfrwd+=solve(i-1,j+1,mat,dp);
        int botfrwd=mat[i][j];
        if(i+1<n)botfrwd+=solve(i+1,j+1,mat,dp);
        
        return dp[i][j]=max(frwd,max(topfrwd,botfrwd));
        
    }
    
    int maxGold(int n, int m, vector<vector<int>> mat)
    {
        // code here
        int maxi=-1e9;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            maxi=max(maxi,solve(i,0,mat,dp));
        }
        
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends