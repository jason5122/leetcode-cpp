#include "debugging.h"
#include "leetcode.h"
using namespace std;

// n == arr.size()
// k == length of strings in arr
// runtime: O(k*2^n)
class Solution {
    vector<string> arr;
    vector<bool> selected_strings;
    unordered_set<char> letters;

    int get_solution_length() {
        int len = 0;
        for (int i = 0; i < selected_strings.size(); i++) {
            if (selected_strings[i]) len += arr[i].length();
        }
        return len;
    }

    int concatenate(int i) {
        if (i == arr.size()) return get_solution_length();

        bool can_concatenate = true;
        unordered_set<char> seen;
        for (char ch : arr[i]) {
            if (seen.count(ch)) {
                can_concatenate = false;
                break;
            }

            if (letters.count(ch)) {
                can_concatenate = false;
                break;
            }

            seen.insert(ch);
        }

        int with = 0;
        if (can_concatenate) {
            selected_strings[i] = true;
            letters.insert(arr[i].begin(), arr[i].end());

            with = concatenate(i + 1);

            selected_strings[i] = false;
            for (char ch : arr[i]) letters.erase(ch);
        }
        int without = concatenate(i + 1);

        return max(with, without);
    }

public:
    int maxLength(vector<string>& arr) {
        this->arr = arr;
        selected_strings = vector(arr.size(), false);
        return concatenate(0);
    }
};

// n == arr.size()
// k == length of strings in arr
// runtime: O(2*k*2^n)
class Solution2 {
    vector<string> arr;
    vector<bool> selected_strings;
    unordered_set<char> letters;

    unordered_map<int, unordered_map<int, int>> cache;

    int get_solution_length() {
        int len = 0;
        for (int i = 0; i < selected_strings.size(); i++) {
            if (selected_strings[i]) len += arr[i].length();
        }
        return len;
    }

    int selected_to_bitmask() {
        int bitmask = 0;
        for (int i = 0; i < selected_strings.size(); i++) {
            if (selected_strings[i]) {
                bitmask |= 1 << i;
            }
        }
        return bitmask;
    }

    int cached_concatenate(int i) {
        int bitmask = selected_to_bitmask();
        if (cache.count(i) && cache[i].count(bitmask)) {
            return cache[i][bitmask];
        } else {
            int result = concatenate(i);
            cache[i][bitmask] = result;
            return result;
        }
    }

    int concatenate(int i) {
        if (i == arr.size()) return get_solution_length();

        bool can_concatenate = true;
        unordered_set<char> seen;
        for (char ch : arr[i]) {
            if (seen.count(ch)) {
                can_concatenate = false;
                break;
            }

            if (letters.count(ch)) {
                can_concatenate = false;
                break;
            }

            seen.insert(ch);
        }

        int with = 0;
        if (can_concatenate) {
            selected_strings[i] = true;
            letters.insert(arr[i].begin(), arr[i].end());

            with = cached_concatenate(i + 1);

            selected_strings[i] = false;
            for (char ch : arr[i]) letters.erase(ch);
        }
        int without = cached_concatenate(i + 1);

        return max(with, without);
    }

public:
    int maxLength(vector<string>& arr) {
        this->arr = arr;
        selected_strings = vector(arr.size(), false);
        return concatenate(0);
    }
};

int main() {
    Solution2 soln;
    int result;
    vector<string> arr;

    soln = Solution2();
    arr = {"un", "iq", "ue"};
    result = soln.maxLength(arr);
    cout << result << '\n';  // 4

    soln = Solution2();
    arr = {"cha", "r", "act", "ers"};
    result = soln.maxLength(arr);
    cout << result << '\n';  // 6

    soln = Solution2();
    arr = {"abcdefghijklmnopqrstuvwxyz"};
    result = soln.maxLength(arr);
    cout << result << '\n';  // 26
}
