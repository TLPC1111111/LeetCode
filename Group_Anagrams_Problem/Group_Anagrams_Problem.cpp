class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector <string>> result_strs;
        unordered_map<string, vector<string>> mp;
        for (auto& str : strs)
        {
            string sort_str = str;
            sort(sort_str.begin(), sort_str.end());
            mp[sort_str].push_back(str);
        }
        for (auto& flag : mp)
        {
            result_strs.push_back(flag.second);
        }
        return result_strs;
    }
};