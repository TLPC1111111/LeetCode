class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 1;
        int max_result = 0;
        sort(nums.begin(), nums.end());
        if (nums.empty()) return 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                continue;
            }
            else if (nums[i] + 1 == nums[i + 1])
            {
                result++;
            }
            else
            {
                max_result = max(max_result, result);
                result = 1;
            }
        }
        return max(max_result, result);
    }
};