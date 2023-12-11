//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long long int sum = 0 ;
        long long int checksum = 0 ;
        int i =0 , j=0;
        for(i=0; i<k; i++)
        {
            sum =sum + arr[i];
        }
        i=k;
        checksum = sum;
        while(i<n)
        {
            checksum = checksum + arr[i] - arr[j];
            sum = max(sum, checksum);
            i++;
            j++;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends