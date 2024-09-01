class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int ans = 0; // ���ڴ洢���ս��
        int current_sum = 0; // ��ǰ��ǰ׺��
        unordered_map<int, int> sum_count; // ��ϣ���洢ǰ׺�ͼ�����ִ���
        sum_count[0] = 1; // ��ʼ����ǰ׺��Ϊ0�Ĵ���Ϊ1�������������ʼλ�ÿ�ʼ�������飩

        for (int num : nums) {
            current_sum += num; // ���µ�ǰǰ׺��

            // ����Ƿ����һ��֮ǰ��ǰ׺�ͣ�ʹ�� current_sum - previous_sum = k
            if (sum_count.find(current_sum - k) != sum_count.end()) {
                ans += sum_count[current_sum - k]; // ������������������������
            }

            // ���¹�ϣ���е�ǰǰ׺�͵ĳ��ִ���
            sum_count[current_sum]++;
        }

        return ans; // �������ս��
    }
};