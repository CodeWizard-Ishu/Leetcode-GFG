//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)  {
    vector<char> stack;
    for(char c: x) {
        if(stack.size() == 0 and (c == ')' or c == ']' or c == '}'))
            return false;
        else if((c == ')' and stack.back() == '(') or (c == ']' and stack.back() == '[') or (c == '}' and stack.back() == '{'))
            stack.pop_back();
        else
            stack.push_back(c);
    }
    return not stack.size();
}
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends