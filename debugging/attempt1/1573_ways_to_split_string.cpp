#include <iostream>
using namespace std;

int numWays(string &s, int i, int i1, int i2, int c1, int c2, int c3) {
    if (i == s.length()) {
        if (i1 == -1 || i2 == -1) return 0;

        // cout << s.substr(0, i1) << '|' << s.substr(i1, i2 - i1) << '|'
        //      << s.substr(i2) << ": " << c1 << ", " << c2 << ", " << c3 <<
        //      '\n';
        return (c1 == c2) && (c2 == c3);
    }

    int isOne = s[i] == '1';

    // set first partition
    if (i1 == -1) {
        return numWays(s, i + 1, i1, i2, c1 + isOne, c2, c3) +
               numWays(s, i + 1, i, i2, c1, isOne, c3);
    }
    // set second partition
    else if (i2 == -1) {
        return numWays(s, i + 1, i1, i2, c1, c2 + isOne, c3) +
               numWays(s, i + 1, i1, i, c1, c2, isOne);
    }
    // already finished partitioning
    else {
        return numWays(s, i + 1, i1, i2, c1, c2, c3 + isOne);
    }
}

int numWays(string s) {
    int isOne = s[0] == '1';
    return numWays(s, 1, -1, -1, isOne, 0, 0);
}

int main() {
    int result = numWays("10101");
    cout << result << '\n';  // 4

    result = numWays("1001");
    cout << result << '\n';  // 0

    result = numWays("0000");
    cout << result << '\n';  // 3

    // result = numWays(
    //     "000000000000000000000000011001000100100000000000000000000000000000000"
    //     "000010000100000000000000100000010010000000000100000000000001010000001"
    //     "110000001000100001000000001000000000010000011000101000001000000000000"
    //     "000000010000000000000010000000001000000000000001000010000000100000001"
    //     "000000000000100000000100001000000000010000000000000000100100000100000"
    //     "001000000000010000000000000000000000000000000010101000000000001000000"
    //     "101000000000000000000000001000011010000001000000000000000000010000000"
    //     "000000000000010100100000010000000010100000000100100000000000000000000"
    //     "000000100000100000000000000100000000000000000000000001000000000000101"
    //     "001010000000011000100010001");
    // cout << result << '\n';
}
