class Solution {
public:

    /*       VECTOR APPROACH       */

    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        vector<int> v(size+1,0);
        int missing = 0, duplicate = 0;
        for(int i=0;i<size;i++)
        {
            v[nums[i]]++;
        }
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==2)
                duplicate = i;
            if(v[i]==0)
                missing = i;
        }
        return {duplicate,missing};
    }

    /*        MAP APPROACH         */

    
};