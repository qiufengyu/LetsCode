class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        cnt, res = 0, k
        for i in range(k):
            cnt += (1 if blocks[i] == 'B' else 0)
        res = min(res, k - cnt)
        for i in range(k, len(blocks)):
            cnt += (1 if blocks[i] == 'B' else 0)
            cnt -= (1 if blocks[i - k] == 'B' else 0)
            res = min(res, k - cnt)
        return res
