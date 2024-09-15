#include <iostream>
#include <vector>
using namespace std;

// n == letters.size()
// runtime: O(n)
// space: O(1)
char next_greatest_letter(vector<char>& letters, char target) {
    for (char letter : letters) {
        if (target < letter) return letter;
    }
    return letters[0];
}

// n == letters.size()
// runtime: O(log n)
// space: O(1)
char next_greatest_letter2(vector<char>& letters, char target) {
    int low = 0;
    int high = letters.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target >= letters[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // low is now pointing to the next greatest letter

    if (low == letters.size()) return letters[0];
    return letters[low];
}

int main() {
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    char result = next_greatest_letter2(letters, target);  // 'c'
    cout << result << '\n';

    letters = {'c', 'f', 'j'};
    target = 'c';
    result = next_greatest_letter2(letters, target);  // 'f'
    cout << result << '\n';

    letters = {'c', 'f', 'j'};
    target = 'd';
    result = next_greatest_letter2(letters, target);  // 'f'
    cout << result << '\n';
}
