class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int curr_sum = 0;
        int expected_sum = (n*(n+1))/2;
        for(auto it : nums)
            curr_sum = curr_sum + it;

        return expected_sum - curr_sum;
    }
};