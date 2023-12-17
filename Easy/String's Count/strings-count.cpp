//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends

long long int countStr(long long int n){
    //complete the function here
    long  long a = n*n*n;
    long long b = 3*n;
    long long c = 2;
    return (a+b+c)/2;
}