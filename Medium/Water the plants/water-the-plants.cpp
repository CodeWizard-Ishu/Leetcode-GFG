//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int min_sprinklers(int gallery[], int n) {
        const int INF = INT_MAX;
        int coverage[n];
        for (int i = 0; i < n; ++i) {
            coverage[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            if (gallery[i] != -1) {
                int left = std::max(0, i - gallery[i]);
                int right = std::min(n - 1, i + gallery[i]);
                for (int j = left; j <= right; ++j) {
                    coverage[j] = std::max(coverage[j], right);
                }
            }
        }
        int count = 0;
        int curr_end = -1;

        for (int i = 0; i < n; ++i) {
            if (coverage[i] == -1) {
                return -1;
            }
            if (i > curr_end) {
                ++count;
                curr_end = coverage[i];
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends