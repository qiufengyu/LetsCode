class Solution:
    def checkRecord(self, n: int) -> int:
        mod = 1000000007

        # ll0 = 0, ll1 = 0, l0 = 1, l1 = 0, a = 1, p0 = 1, p1 = 0
        ll0, ll1, l0, l1, a, p0, p1 = 0, 0, 1, 0, 1, 1, 0
        for i in range(1, n):
            templl0, templl1, templ0, templ1, tempa, tempp0, tempp1 = \
                ll0, ll1, l0, l1, a, p0, p1

            ll0 = templ0
            ll1 = templ1
            l0 = tempp0
            l1 = (tempp1 + tempa) % mod
            a = (templl0 + templ0 + tempp0) % mod
            p0 = (templl0 + tempp0 + templ0) % mod
            p1 = (templl1 + tempp1 + tempa + templ1) % mod

        return (ll0 + ll1 + l0 + l1 + a + p0 + p1) % mod
