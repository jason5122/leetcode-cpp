#include "debugging.h"
#include "leetcode.h"
using namespace std;

int main() {
    auto compare = [](int a, int b) { return b > a; };

    priority_queue<int, vector<int>, decltype(compare)> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);

    while (!pq.empty()) {
        int k = pq.top();
        pq.pop();
        cout << k << ' ';
    }
    cout << '\n';
}
