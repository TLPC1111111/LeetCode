class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        int ans = 0;
        int max_ans = 0;
        unordered_set<char> stock;

        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            while (stock.find(s[right]) != stock.end())
            {
                stock.erase(s[left]);
                left++;
            }
            stock.insert(s[right]);
            ans = right - left + 1;
            max_ans = max(max_ans, ans);
        }

        return max_ans;
    }
};
