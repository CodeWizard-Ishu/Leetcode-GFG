class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mp;
        int repeated = 0;
        for(int i=0; i < nums.size(); i++)
        {
            ++mp[nums[i]];
        }
        
        for(auto it : mp)
        {
            if(it.second > 1)
            {
                repeated = it.first;
                break;
            }
        }
        return repeated;
    }
};