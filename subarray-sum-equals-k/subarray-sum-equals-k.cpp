class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int ans = 0; // 用于存储最终结果
        int current_sum = 0; // 当前的前缀和
        unordered_map<int, int> sum_count; // 哈希表，存储前缀和及其出现次数
        sum_count[0] = 1; // 初始化：前缀和为0的次数为1（处理从数组起始位置开始的子数组）

        for (int num : nums) {
            current_sum += num; // 更新当前前缀和

            // 检查是否存在一个之前的前缀和，使得 current_sum - previous_sum = k
            if (sum_count.find(current_sum - k) != sum_count.end()) {
                ans += sum_count[current_sum - k]; // 增加满足条件的子数组数量
            }

            // 更新哈希表中当前前缀和的出现次数
            sum_count[current_sum]++;
        }

        return ans; // 返回最终结果
    }
};