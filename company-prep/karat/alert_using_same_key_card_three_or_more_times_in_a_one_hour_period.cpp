/*
n == keyName.size()
runtime: O(n*lg(n))
space: O(n)
*/
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<pair<int, string>> pairs;
        for (int i = 0; i < keyName.size(); i++) {
            int time = convert_time(keyTime[i]);
            pairs.push_back({time, keyName[i]});
        }

        // Earlier times come first.
        sort(pairs.begin(), pairs.end());

        vector<string> ans;
        unordered_set<string> seen;

        unordered_map<string, queue<int>> uses;
        for (auto& [time, name] : pairs) {
            auto& q = uses[name];
            while (!q.empty() && time - q.front() > 60) {
                q.pop();
            }

            q.push(time);
            if (q.size() >= 3 && !seen.contains(name)) {
                ans.push_back(name);
                seen.insert(name);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }

private:
    int convert_time(string& time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3));
        return hours * 60 + minutes;
    }
};
