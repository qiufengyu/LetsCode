#include "../header.h"

class Solution {
private:
    vector<int> res;
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int nr = req_skills.size(), np = people.size();
        unordered_map<string, int> dict;
        for (int i = 0; i < nr; i++) {
            dict[req_skills[i]] = (1 << i);
        }
        vector<int> people_skill;
        for (auto const& p: people) {
            int mask = 0;
            for (int i = 0; i < p.size(); i++) {
                if (dict.count(p[i]) != 0) {
                    mask |= dict[p[i]];
                }
            }
            people_skill.push_back(mask);
        }
        vector<vector<int>> dp(np, vector<int>((1<<nr), -1));
        vector<int> current;
        helper(people_skill, 0, nr, 0, dp, current);
        return res;
    }

    void helper(vector<int>& people_skill, int mask, int nr, int index, vector<vector<int>>& dp, vector<int>& current) {
        if (index == people_skill.size()) {
            if (mask == (1 << nr) - 1) {
                if (res.size() == 0 || current.size() < res.size()) {
                    res = current;
                }
            }
            return;
        }
        if (dp[index][mask] != -1) {
            if (dp[index][mask] <= current.size()) {
                return;
            }
        }
        helper(people_skill, mask, nr, index + 1, dp, current);
        current.push_back(index);
        helper(people_skill, (mask | people_skill[index]), nr, index+1, dp, current);
        current.pop_back();
        if (current.size() > 0) {
            dp[index][mask] = current.size();
        }
    }
};