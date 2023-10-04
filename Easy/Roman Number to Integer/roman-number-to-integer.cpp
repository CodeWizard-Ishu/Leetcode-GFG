//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
          
        int i=0;
        int ans=0;
        int n=str.size();
        while(i<n){
            if(i+1<n&&mp[str[i]]<mp[str[i+1]]){
                ans+=mp[str[i+1]]-mp[str[i]];
                i+=2;
            }
            else{
                ans+=mp[str[i]];
                i++;
            }
        }
        return ans;   
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends