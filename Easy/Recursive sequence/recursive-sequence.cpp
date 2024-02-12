//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        long long ans=0;
        int st=1;
        long long mod=1e9+7;
        for(int i=1;i<n+1;i++){
            long long cur=1;
            int j=0;
            while(j<i){
                cur=(cur*st)%mod;
                st++;
                j++;
            }
            ans=(ans+cur)%mod;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends