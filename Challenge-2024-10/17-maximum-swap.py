class Solution:
    def maximumSwap(self, num: int) -> int:
        ns = list(str(num))
        no_swap = True
        for i in range(1, len(ns)):
            if ns[i] > ns[i-1]:
                no_swap = False
                break
        if no_swap:
            return num
        sorted_list = []
        for i in range(len(ns)):
            sorted_list.append((-int(ns[i]), i))
        sorted_list.sort()
        for i in range(len(ns)):
            if int(ns[i]) != -sorted_list[i][0]:
                tmp = ns[i]
                ns[i] = str(-sorted_list[i][0])
                j = i
                while j < len(ns) and sorted_list[j][0] == sorted_list[i][0]:
                    j += 1
                ns[sorted_list[j-1][1]] = tmp
                break
        return int(''.join(ns))

