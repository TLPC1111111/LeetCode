class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;//¼ÇÂ¼Ë÷Òý(Î»ÖÃ)
        for (int i = 0; i < nums.size(); i++)
        {
            if (!deq.empty() && deq.front() + k < i + 1)
            {
                deq.pop_front();
            }
            while (!deq.empty() && nums[deq.back()] < nums[i])
            {
                deq.pop_back();
            }
            deq.push_back(i);
            if (i - k + 1 >= 0)
            {
                ans.push_back(nums[deq.front()]);
            }
        }
        return ans;
    }
};
