#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// n == text.length()
// runtime: O(n)
// space: O(n)
int max_number_of_balloons(string text) {
    unordered_map<char, int> freqs;
    for (char c : text) freqs[c]++;

    return min(
        {freqs['b'], freqs['a'], freqs['l'] / 2, freqs['o'] / 2, freqs['n']});
}

int main() {
    int result;
    string text;

    text = "nlaebolko";
    result = max_number_of_balloons(text);
    cout << result << '\n';  // 1

    text = "loonbalxballpoon";
    result = max_number_of_balloons(text);
    cout << result << '\n';  // 2

    text = "leetcode";
    result = max_number_of_balloons(text);
    cout << result << '\n';  // 0
}
