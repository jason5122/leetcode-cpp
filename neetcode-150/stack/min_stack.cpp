class MinStack {
    stack<int> val_stack;
    stack<int> min_stack;

public:
    MinStack() {}

    void push(int val) {
        val_stack.push(val);

        if (!min_stack.empty() && min_stack.top() < val) {
            min_stack.push(min_stack.top());
        } else {
            min_stack.push(val);
        }
    }

    void pop() {
        val_stack.pop();
        min_stack.pop();
    }

    int top() {
        return val_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};
