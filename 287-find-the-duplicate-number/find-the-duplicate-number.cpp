class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // map<int, int> mp;
        // int repeated = 0;
        // for(int i=0; i < nums.size(); i++)
        // {
        //     ++mp[nums[i]];
        // }
        
        // for(auto it : mp)
        // {
        //     if(it.second > 1)
        //     {
        //         repeated = it.first;
        //         break;
        //     }
        // }
        // return repeated;

        // APPROACH - 2

        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while ( slow != fast);

        slow = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};