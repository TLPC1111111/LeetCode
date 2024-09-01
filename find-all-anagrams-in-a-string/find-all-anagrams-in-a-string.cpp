class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> target(26, 0), flag(26, 0);
        int index = 0;
        int right = 0;
        for (auto& c : p)
        {
            flag[c - 'a']++;
        }
        while (right < s.size())
        {
            target[s[right] - 'a']++;
            right++;
            if (right - index < p.size())
            {
                continue;
            }
            else
            {
                if (target == flag)
                {
                    ans.push_back(index);
                    target[s[index] - 'a']--;
                    index++;
                }
                else
                {
                    target[s[index] - 'a']--;
                    index++;
                }
            }
        }
        return ans;
    }
};