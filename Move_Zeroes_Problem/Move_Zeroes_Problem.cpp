class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int not_zero_index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[not_zero_index] = nums[i];
                not_zero_index++;
            }
        }
        while (not_zero_index < nums.size())
        {
            nums[not_zero_index] = 0;
            not_zero_index++;
        }
    }
};