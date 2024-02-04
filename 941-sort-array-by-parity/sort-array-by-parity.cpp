class Solution {
public:
    // void help(int a, int b)
    // {
    //     int temp;
    //     temp = a;
    //     a = b;
    //     b= temp;
    // }
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i=0, j=0;i<nums.size();i++)
        {
            if(nums[i]%2 == 0)
            {
                swap(nums[j], nums[i]);
                j++;
            }
        }
        // sort(nums.begin(), nums.end());
        return nums;
    }
};