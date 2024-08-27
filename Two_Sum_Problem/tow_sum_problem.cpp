class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++)
        {
            int flag = target - nums[i];
            if (num_map.find(flag) != num_map.end())
            {
                return  { num_map[flag] , i };
            }
            num_map[nums[i]] = i;
        }
        return { 1, 1 };
    }
};