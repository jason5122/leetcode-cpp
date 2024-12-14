/*
USED DEBUGGING
n == s.length()
runtime: O(n*lg(26))
space: O(26)
*/
class Solution {
public:
    string reorganizeString(string s) {
        int freqs[26] = {0};
        for (char ch : s) freqs[ch - 'a']++;

        auto comp = [&](char c1, char c2) { return freqs[c1 - 'a'] < freqs[c2 - 'a']; };
        priority_queue<char, vector<char>, decltype(comp)> pq(comp);
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freqs[ch - 'a'] > 0) pq.push(ch);
        }

        string ans;
        while (!pq.empty()) {
            // If the char is the same, temporarily remove it.
            char temp = '\0';
            if (!ans.empty() && ans.back() == pq.top()) {
                temp = pq.top();
                pq.pop();
            }

            // If there are no alternatives, there is no solution.
            if (pq.empty()) return "";

            char ch = pq.top();
            ans += ch;
            freqs[ch - 'a']--;
            if (freqs[ch - 'a'] == 0) pq.pop();

            // Restore temp char.
            if (temp != '\0') pq.push(temp);
        }
        return ans;
    }
};

/*
n == s.length()
runtime: O(n*lg(26))
space: O(26)
*/
class Solution {
public:
    string reorganizeString(string s) {
        int freqs[26] = {0};
        for (char ch : s) freqs[ch - 'a']++;

        priority_queue<pair<int, char>> pq;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int freq = freqs[ch - 'a'];
            if (freq > 0) pq.push({freq, ch});
        }

        string ans;
        while (!pq.empty()) {
            // If the char is the same, temporarily remove it.
            pair<int, char> temp = {0, '\0'};
            if (!ans.empty() && ans.back() == pq.top().second) {
                temp = pq.top();
                pq.pop();
            }

            // If there are no alternatives, there is no solution.
            if (pq.empty()) return "";

            auto [freq, ch] = pq.top();
            pq.pop();
            ans += ch;
            if (freq > 1) pq.push({freq - 1, ch});

            // Restore temp char.
            if (temp.second != '\0') pq.push(temp);
        }
        return ans;
    }
};
