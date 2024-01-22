class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    
    /*       VECTOR APPROACH       */

    //     int size = nums.size();
    //     vector<int> v(size+1,0);
    //     int missing = 0, duplicate = 0;
    //     for(int i=0;i<size;i++)
    //     {
    //         v[nums[i]]++;
    //     }
    //     for(int i=1;i<v.size();i++)
    //     {
    //         if(v[i]==2)
    //             duplicate = i;
    //         if(v[i]==0)
    //             missing = i;
    //     }
    //     return {duplicate,missing};
    // }

    /*        MAP APPROACH         */

        int size = nums.size();
        int duplicate = 0, missing = 0;
        unordered_map<int, int> mp;

        for(int i=1;i<=size;i++)
            mp[i]++;

        for(auto i : nums)
            mp[i]--;

        for(auto i : mp)
        {
            if(i.second == -1)
                duplicate = i.first;
            if(i.second == 1)
                missing = i.first;
        }

        return {duplicate,missing};
    }
};