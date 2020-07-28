class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count_tasks(26, 0);
        int max_ = 0;
        for (auto task : tasks) {
            count_tasks[task - 65]++;
            if (max_ < count_tasks[task - 65]) {
                max_ = count_tasks[task - 65];
            }
        }
        
        int empty_pos = (max_ - 1) * (n + 1) + 1;
        for (int i = 25; i >= 0; i--) {
            if (count_tasks[i] == max_) empty_pos++;
            empty_pos -= count_tasks[i];
        }
        
        empty_pos = empty_pos > 0 ? empty_pos : 0;
        int result = max(tasks.size(), tasks.size() + empty_pos - 1);
        return result;
    }
};
