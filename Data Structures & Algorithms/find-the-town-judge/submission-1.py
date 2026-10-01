class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        mp = {i: [0,0] for i in range(1, n+1) }
        for i in trust:
            mp[i[1]][0] += 1
            mp[i[0]][1] += 1

        for i in mp:
            if mp[i][1] == 0 and mp[i][0] == n-1:
                return i
        
        return -1
