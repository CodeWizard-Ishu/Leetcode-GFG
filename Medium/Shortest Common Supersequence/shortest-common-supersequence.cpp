//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int solve(string X,string Y, int m, int n, int i , int j , vector<vector<int>>&dp){
        
        // base case
        if(i >= m || j >= n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        // Process
        if(X[i] == Y[j]){
            return 1 + solve(X,Y,m,n,i+1,j+1,dp);
        }
        
        int ans1 = solve(X,Y,m,n,i+1,j,dp);
        int ans2 = solve(X,Y,m,n,i,j+1,dp);
        dp[i][j] =  max(ans1,ans2);
        return dp[i][j];
        
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int x = solve(X,Y,m,n,0,0,dp);
        return n + m - x;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends