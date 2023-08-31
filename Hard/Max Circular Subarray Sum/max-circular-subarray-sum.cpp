//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
int kadans(int arr[], int n){
       int res=INT_MIN;
       for(int i=0;i<n;i++){
           if(res<arr[i]) res=arr[i];
       }
       if(res<0) return res;
       int c_sum=0;
       for(int i=0;i<n;i++){
           c_sum+=arr[i];
           if(c_sum<0) c_sum=0;
           res=max(res,c_sum);
       }
       return res;
   }
class Solution{
    public:
    int circularSubarraySum(int arr[], int num){
         if(num==1) return arr[0];
       int k_ans=kadans(arr,num);
       if(num==2) return k_ans;
       int c_ans=INT_MIN;
       int asum=0;
       for(int i=0;i<num;i++){
           asum+=arr[i];
           arr[i]=-arr[i];
       }
       for(int i=0;i<num-2;i++){
           arr[i]=arr[i+1];
       }
       int maxx=kadans(arr,num-2);
       c_ans=asum+maxx;
       return max(c_ans,k_ans);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends