//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        queue<pair<int,int>> q;
        int n=matrix.size();
        q.push({0,0});
        int l[]={0,1,-1,0};
        int r[]={1,0,0,-1};
        if(matrix.size()==1)
         return {matrix[0][0]};
         vector<vector<int>> solu(n,vector<int>(n,-1));
         solu[0][0]=1;
        vector<int> sol;
        while(!q.empty())
        {
            int a=q.front().first;
            int b=q.front().second;
            sol.push_back(matrix[a][b]);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int c=a+l[i];
                int d=b+r[i];
            if(c>=0 && d>=0 && c<n && d<n && solu[c][d]==-1)
            {
                solu[c][d]=1;
                q.push({c,d});
            }
            }
            
        }
        return sol;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends