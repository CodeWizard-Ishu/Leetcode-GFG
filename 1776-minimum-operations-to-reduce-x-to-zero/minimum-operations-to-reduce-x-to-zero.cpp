class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for (int i : nums)
            sum += i;
        
        int target = sum - x;
        int curr_sum = 0, max_len = 0;
        int i = 0;
        bool found = false;

        for (int j = 0; j < n; j++)
        {
            curr_sum = curr_sum + nums[j];
            while (i<=j && curr_sum>target)
            {
                curr_sum = curr_sum - nums[i];
                ++i;
            }
            if (curr_sum == target) {
                found = true;
                max_len = max(max_len, j-i+1);
            }
        }
        if(found == true)
            return n-max_len;
        else
            return -1;
    }
};