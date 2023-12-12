class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximum=0;
        int second_maximum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(maximum<=nums[i])
            {
                second_maximum=maximum;
                maximum=nums[i];
            }
            else if(second_maximum<=nums[i])
                second_maximum=nums[i];
        }
        return (maximum-1)*(second_maximum-1);
    }
};