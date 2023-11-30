//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
      
    int f(int n){
        if(n == 1) return 0;
        if(n%3 == 0){
            return 1+f(n/3);
        }
        else{
            return 1 + f(n-1);
        }
    }

    int minimumStep(int n){
        //complete the function here
        int ans = f(n);
        return ans;
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
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends