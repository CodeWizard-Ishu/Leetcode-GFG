//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int i = 0;
            vector<int> ans;
            
            // iterate till the input string txt contains enough characters to compare
            while (i < txt.length() - pat.length() + 1) 
            {
                int j = 0;
                while (j < pat.length() && pat[j] == txt[i + j]) // dimag ki batti jalao..
                {
                    j++;
                }
                
                if (j == pat.length()) 
                {
                    ans.push_back(i + 1);
                }
                
                i++;
            }
            
            if(ans.size() > 0) return ans;
            else return {-1};
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends