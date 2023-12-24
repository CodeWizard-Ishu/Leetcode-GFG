//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        int sum=0, count=0;
        multimap<int, int> mp; 
        
        for(int i=0; i<n; i++){
            mp.insert(make_pair(price[i], i+1));
        }
        
        for(auto it : mp){
            if(((k-sum)/(it.first))==0){
                break;
            }
            int x = min(((k-sum)/(it.first)), it.second);
            count+=x;
            sum += x*(it.first);
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
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends