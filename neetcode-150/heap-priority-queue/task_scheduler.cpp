/*
USED SOLUTION
n == tasks.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char t : tasks) freq[t - 'A']++;

        priority_queue<int> pq;
        for (int c : freq) {
            if (c > 0) pq.push(c);
        }

        int cycle_len = n + 1;

        int time = 0;
        while (!pq.empty()) {
            int task_count = 0;
            vector<int> extracted;

            int i = cycle_len;
            while (i-- && !pq.empty()) {
                int c = pq.top();
                pq.pop();

                if (c > 1) extracted.push_back(c - 1);
                task_count++;
            }

            for (int c : extracted) {
                pq.push(c);
            }

            time += pq.empty() ? task_count : cycle_len;
        }
        return time;
    }
};
