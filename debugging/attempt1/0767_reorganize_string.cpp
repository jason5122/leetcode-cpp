#include "debugging.h"
#include "leetcode.h"
using namespace std;

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

int main() {
    Solution soln;
    string s;
    string ans;

    soln = Solution();
    s = "aab";
    ans = soln.reorganizeString(s);
    cout << ans << '\n';  // "aba"

    soln = Solution();
    s = "aaab";
    ans = soln.reorganizeString(s);
    cout << ans << '\n';  // ""

    // USED TEST CASE
    soln = Solution();
    s = "snnnnbpngobwznvnnnlnwhvnnnnfjnnlnnnnnnbnknnqkndzefncknnnnnaiqrntnndnnnjninnnunnunqhndnnqn"
        "nsjqnnpiqshntnnncnvnnnncnnqenlnninyndnnnljongnnjwnnnngllnnngkbnllnnnnontlbpngjnnenqnsnnnn"
        "njeqqghnfpngepnodnnnnnnvnsrnughbnipvnhqmnzonoonnnjotnnonoennnpnfnnkdnnbmnmnpnqninnxronnnn"
        "vnlanlnnnebnnnlnvnfknsnbincnttnmnguqenhnnxunnnntnnnnhnqnzehvunfnvnndvnjnnnbnnpxnqipwnmnon"
        "nndlnsnonnninnxnnnjnnnnnesennmyiednnnnnnnnnhimtnnnonjlicnwnwvnntaxmnrntnnnnsnbnanninnecbc"
        "fjxncnnkvnnqgnunensanpnngjnzxjnopnnyvnnxskniyytnsnnnnx";
    ans = soln.reorganizeString(s);
    cout << ans << '\n';
    // nqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnonononononononononononononononenenenenenenenenenenenenenenininininininininininininininjnjnjnjnjnjnjnjnjnjnjnjnjnjnlnlnlnlnlnlnlnlnlnlnlnlnlnlnvnvnvnvnvnvnvnvnvnvnvnvnvnbnbnbnbnbnbnbnbnbnbnbnbnpnpnpnpnpnpnpnpnpnpnpnpnsnsnsnsnsnsnsnsnsnsnsnsngngngngngngngngngngngntntntntntntntntntntntnhnhnhnhnhnhnhnhnhnhndndndndndndndndndnxnxnxnxnxnxnxnxnxncncncncncncncncnknknknknknknknknmnmnmnmnmnmnmnmnfnfnfnfnfnfnfnunununununununwnwnwnwnwnwnanananananynynynynynznznznznznrnrnrnrn
}
