#include "../header.h"

struct Task {
    int index, start, process;
    Task(int i, int s, int p): index{i}, start{s}, process{p} {};
    friend bool operator<(const Task& t1, const Task& t2);
};

void printTask(Task t) {
    cout << "index: " << t.index << ", start: " << t.start << ", process: " << t.process << endl;
}

bool operator<(const Task& t1, const Task& t2) {
    if (t1.process == t2.process) {
        return t1.index > t2.index;
    } 
    return t1.process > t2.process;
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<Task> v;
        for (int i = 0; i < tasks.size(); ++i) {
            Task task{i, tasks[i][0], tasks[i][1]};
            v.push_back(task);
        }
        sort(v.begin(), v.end(), [](const Task& t1, const Task& t2) {
            return t1.start < t2.start;
        });
        vector<int> res;
        auto task = v[0];
        long lastStart = (long)task.start;
        int lastIndex = 0;
        auto cmp = [](const Task& t1, const Task& t2) {
            if (t1.process == t2.process) {
                return t1.index > t2.index;
            } 
            return t1.process > t2.process;
        };
        priority_queue<Task, vector<Task>, decltype(cmp)> pq(cmp);
        while (lastIndex < tasks.size()) {
            if ((long)(v[lastIndex].start) <= lastStart) {
                pq.push(v[lastIndex]);
                lastIndex++;
            } else {
                break;
            }
        }
        while (!pq.empty() || lastIndex < tasks.size()) {
            // may start from a new available task -> cpu has idle cycle
            if (pq.empty()) {                
                int startTime = v[lastIndex].start;
                lastStart = startTime;
                cout << "empty, update lastStart = " << startTime << endl;
                while (lastIndex < tasks.size() && v[lastIndex].start == startTime) {
                    pq.push(v[lastIndex]);
                    ++lastIndex;
                }
            }
            auto t = pq.top();
            printTask(t);
            pq.pop();
            res.push_back(t.index);
            lastStart += (long)t.process;
            cout << "new start: " << lastStart << endl;
            cout << "start index: " << lastIndex << endl;
            while (lastIndex < tasks.size()) {
                if ((long)(v[lastIndex].start) <= lastStart) {
                    pq.push(v[lastIndex]);
                    lastIndex++;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> tasks{{5,2},{7,2},{9,4},{6,3},{5,10},{1,1}};
    vector<int> res = Solution().getOrder(tasks);
    print_vector<int>(res);
    return 0;
}