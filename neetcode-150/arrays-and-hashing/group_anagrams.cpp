/*
n == strs.size()
k == strs[0].length()
runtime: O(n*k*lg k)
space: O(n*k)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end());

            groups[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (const auto& [key, group] : groups) ans.push_back(group);
        return ans;
    }
};
