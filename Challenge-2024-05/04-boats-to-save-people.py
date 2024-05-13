from typing import List


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        i, j = 0, len(people) - 1
        res = 0
        while i <= j:
            load = people[j]
            if limit - load > 0 and i < j and load + people[i] <= limit:
                load += people[i]
                i += 1
            j -= 1
            res += 1
        return res