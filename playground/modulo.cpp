#include "debugging.h"
#include "leetcode.h"
using namespace std;

inline int positive_modulo(int i, int n) {
    return (i % n + n) % n;
}

int main() {
    cout << positive_modulo(-1, 2) << '\n';
}
