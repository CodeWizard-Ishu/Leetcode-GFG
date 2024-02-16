class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int sum = 0, length = INT_MAX;
        while(j<nums.size())
        {
            sum = sum + nums[j];
            while(sum >= target)
            {
                length = min(length, j-i+1);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        if(length == INT_MAX)
            return 0;
        else
            return length;
    }
};