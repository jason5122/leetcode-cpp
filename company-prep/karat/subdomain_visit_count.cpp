/*
n == cpdomains.size()
m == max # of fragments in a domain

runtime: O(n*m)
space: O(n*m)
*/
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> visits;

        for (auto& s : cpdomains) {
            int i = s.find(' ');
            int rep = stoi(s.substr(0, i));

            string domain = s.substr(i + 1);
            visits[domain] += rep;

            for (int i = 0; i < domain.length(); i++) {
                if (domain[i] == '.') {
                    string sub = domain.substr(i + 1);
                    visits[sub] += rep;
                }
            }
        }

        vector<string> ans;
        for (auto& [d, rep] : visits) {
            ans.emplace_back(to_string(rep) + ' ' + d);
        }
        return ans;
    }
};
