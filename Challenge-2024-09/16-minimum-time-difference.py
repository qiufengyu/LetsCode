from typing import List


class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        timePoints.sort()

        res = 24 * 60

        for i in range(1, len(timePoints)):
            time1, time2 = timePoints[i-1], timePoints[i]
            h1, m1, h2, m2 = int(time1[0:2]), int(time1[3:]), int(time2[0:2]), int(time2[3:])
            diff = (h2 - h1) * 60 + (m2 - m1)
            res = min(res, diff)
        
        diff = 1440 + int(timePoints[0][0:2]) * 60 + int(timePoints[0][3:]) - int(timePoints[-1][0:2]) * 60 - int(timePoints[-1][3:])

        return min(diff, res)