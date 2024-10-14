class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_color;
        unordered_map<int, int> color_count;

        vector<int> ans;
        for (auto& q : queries) {
            int ball = q[0], color = q[1];

            if (ball_color.count(ball)) {
                int old_color = ball_color[ball];
                color_count[old_color]--;

                if (color_count[old_color] == 0) {
                    color_count.erase(old_color);
                }
            }

            ball_color[ball] = color;
            color_count[color]++;

            ans.emplace_back(color_count.size());
        }
        return ans;
    }
};
