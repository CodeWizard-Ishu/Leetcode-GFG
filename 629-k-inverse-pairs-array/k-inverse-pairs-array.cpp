// BOTTOM-UP APPROACH + OPTIMIZATION -> with time complexity -- O(n*k) -> optimal solution

class Solution {
public:
    int M = 1e9+7;

    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1, vector<int>(k+1));
        //t[i][j] = total number of arrays having (1 to i and exactly j inversions

        //for j=0, t[i][0] = 1
        for(int i=0; i<=n; i++){
            t[i][0]=1;
        }

        for(int i=1; i<=n; i++)
        {
            long long cumSum = 1;
            for(int j=1; j<=k; j++)
            {
                cumSum = cumSum + t[i-1][j];
                if(j>=i)
                {
                    cumSum = cumSum - t[i-1][j-i];
                }
                t[i][j] = cumSum % M;
            }
        }
        
        return t[n][k];
    }
};




// // BOTTOM-UP APPROACH -> with time complexity -- O(n*k*n) -> slightly improved but still high runtime

// class Solution {
// public:
//     int M = 1e9+7;

//     int kInversePairs(int n, int k) {
//         vector<vector<int>> t(n+1, vector<int>(k+1));
//         //t[i][j] = total number of arrays having (1 to i and exactly j inversions

//         //for j=0, t[i][0] = 1
//         for(int i=0; i<=n; i++){
//             t[i][0]=1;
//         }

//         for(int i=1; i<=n; i++)
//         {
//             for(int j=1; j<=k; j++)
//             {
//                 for(int inv=0; inv<=min(i-1, j); inv++)
//                 {
//                     t[i][j] = (t[i][j] % M + t[i-1][j-inv] % M) % M;
//                 }
//             }
//         }

//         return t[n][k];
//     }
// };







// // RECURSION + MEMOIZATON -> with time complexity -- O(n*k*n) -> slowest code(very high complexity)

// class Solution {
// public:
//     int M = 1e9+7;
//     int t[1001][1001];

//     int solve(int n, int k)
//     {
//         if(n==0)
//             return 0;

//         if(k==0)
//             return 1;  //in this case only sorted array have 0 inversions

//         if(t[n][k] != -1)
//             return t[n][k];

//         int result = 0;
//         for(int inv=0; inv <= min(k, n-1); inv++) //for an array of length 'n' you can have at max 'n-1' inversions
//             result = (result%M + solve(n-1, k-inv)%M) % M;

//         return t[n][k] = result;
//     }

//     int kInversePairs(int n, int k) {
//         memset(t, -1, sizeof(t));
//         return solve(n,k);
//     }
// };




// // RECURSION -> with time complexity -- O(k^n) -> TIME LIMIT EXCEEDED

// class Solution {
// public:
//     int M = 1e9+7;

    // int solve(int n, int k)
    // {
    //     if(n==0)
    //         return 0;

    //     if(k==0)
    //         return 1;  //in this case only sorted array have 0 inversions

    //     int result = 0;
    //     for(int inv=0; inv <= min(k, n-1); inv++) //for an array of length 'n' you can have at max 'n-1' inversions
    //         result = (result%M + solve(n-1, k-inv)%M) % M;

    //     return result;
    // }

    // int kInversePairs(int n, int k) {
    //     return solve(n,k);
    // }
// };