class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res;
        long long int ans=1;
        res.push_back(1);
        for(int i=0;i<rowIndex;i++)
        {
            ans=ans*(rowIndex-i)/(i+1);
            res.push_back(ans);
        }
        return res;
    }
};