//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    if(n % k != 0) return 0;
        
        vector<int> ind;
        for(int i = 0; i < n; i++) if(i % k == 0 && i + k <= n) ind.push_back(i);
        
        map<string, int> mp;
        for(int i = 0; i < ind.size(); i++){
            string temp = "";
            for(int j = ind[i]; j < ind[i] + k; j++) temp += s[j];
            
            mp[temp]++;
        }
        if(mp.size() == 1) return 1;
        
        int maxi = 0;
        int sum = 0;
        
        for(auto it:mp){
            sum += it.second;
            maxi = max(maxi, it.second);
        }
        sum -= maxi;
        
        if(sum <= maxi) return 1;
        return 0;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends