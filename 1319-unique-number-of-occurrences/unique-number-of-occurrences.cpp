class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        int size1 = arr.size();
        int i = 0;
        sort(arr.begin(), arr.end());
        while(i<size1)
        {
            int count = 1;
            for(int j=i+1;j<size1;j++)
            {
                if(arr[i] == arr[j])
                    count++;
                else
                    break;
            }
            ans.push_back(count);
            i = i+count;
        }
        int size2 = ans.size();
        sort(ans.begin(), ans.end());
        for(int i=0;i<size2-1;i++)
        {
            if(ans[i] == ans[i+1])
                return false;
        }
        return true;
    }
};