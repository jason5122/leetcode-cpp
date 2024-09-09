/*
n == # of hits
runtime: O(n^2)
space: O(n)
*/
class HitCounter {
public:
    HitCounter() {}

    void hit(int timestamp) {
        stk.push(timestamp);
    }

    int getHits(int timestamp) {
        int ans = 0;

        auto temp = stk;
        while (!temp.empty() && timestamp - temp.top() < 300) {
            temp.pop();
            ans++;
        }
        return ans;
    }

private:
    stack<int> stk;
};

/*
USED PARTIAL SOLUTION
n == # of hits
runtime: O(n)
space: O(n)
*/
class HitCounter {
public:
    HitCounter() {}

    void hit(int timestamp) {
        q.push(timestamp);
    }

    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front() >= 300) {
            q.pop();
        }
        return q.size();
    }

private:
    queue<int> q;
};
