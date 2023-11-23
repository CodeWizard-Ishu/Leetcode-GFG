#User function Template for python3

class Solution:
    
    #Function to merge the arrays.
     def merge(self,arr1,arr2,n,m):
        arr = arr1+arr2
        arr.sort()
        arr1[:] = arr[:n]
        arr2[:] = arr[n:]
        #code here
    



#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        n,m = map(int, input().strip().split())
        arr1 = list(map(int, input().strip().split()))
        arr2 = list(map(int, input().strip().split()))
        ob=Solution()
        ob.merge(arr1, arr2, n, m)
        print(*arr1,end=" ")
        print(*arr2)
# } Driver Code Ends