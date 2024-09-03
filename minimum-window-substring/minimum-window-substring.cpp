class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size() || t.empty() || s.empty())
        {
            return "";
        }

        string ans;
        unordered_map<char, int> mp, win_mp;
        for (auto c : t)//将t放入win_map中，出现次数。
        {
            win_mp[c]++;
        }
        int left = 0;
        int right = 0;
        int result = 0;//判断板子中间的元素是否包含t中元素
        int need_lens = t.size();
        int min_len = INT_MAX;//记录最下子串的长度
        int min_left = INT_MAX;//记录最小子串的初始位置
        while (right < s.size())
        {
            mp[s[right]]++;
            if (win_mp.find(s[right]) != win_mp.end() && win_mp[s[right]] >= mp[s[right]])
            {
                result++;
            }
            while (left <= right && result == need_lens)
            {
                if (right - left + 1 < min_len)
                {
                    min_len = right - left + 1;
                    min_left = left;
                }
                //min_len = min(right - left + 1, min_len);
                //min_left = left;
                mp[s[left]]--;
                if (win_mp.find(s[left]) != win_mp.end() && mp[s[left]] < win_mp[s[left]])
                {
                    result--;
                }
                left++;
            }
            right++;
        }
        if (min_len < INT_MAX)
        {
            for (int k = 0; k < min_len; k++)
            {
                if (min_left + k < s.size())
                {
                    ans.push_back(s[min_left + k]);
                }

            }
        }
        return ans;
    }
};