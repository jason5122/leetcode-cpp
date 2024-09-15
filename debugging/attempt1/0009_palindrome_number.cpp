#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    string s = to_string(x);
    return s == string(s.rbegin(), s.rend());
}

int main() {
    while (true) {
        int x;
        cout << "Enter a number: ";
        cin >> x;

        bool result = isPalindrome(x);
        cout << result << '\n';
    }
}
