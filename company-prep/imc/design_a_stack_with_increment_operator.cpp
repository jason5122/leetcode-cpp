/*
push: O(1)
pop: O(1)
increment: O(k)
space: O(maxSize)
*/
class CustomStack {
public:
    CustomStack(int maxSize) : max_size(maxSize) {}

    void push(int x) {
        if (stk.size() >= max_size) return;

        stk.push_back(x);
    }

    int pop() {
        if (stk.empty()) return -1;

        int val = stk.back();
        stk.pop_back();
        return val;
    }

    void increment(int k, int val) {
        auto it = stk.begin();
        while (it != stk.end() && k--) {
            *it += val;
            ++it;
        }
    }

private:
    list<int> stk;
    int max_size;
};
