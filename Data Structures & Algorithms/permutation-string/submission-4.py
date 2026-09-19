class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mp1, mp2 = {}, {}
        j = 0
        n1, n2 = len(s1), len(s2)
        if n1 > n2:
            return False
        for i in range(len(s1)):
            mp1[s1[i]] = 1 if s1[i] not in mp1 else mp1[s1[i]] + 1
            mp2[s2[i]] = 1 if s2[i] not in mp2 else mp2[s2[i]] + 1
            j += 1
        while j < len(s2):
            if mp1 == mp2:
                return True
            mp2[s2[j-n1]] -= 1
            if mp2[s2[j-n1]] == 0:
                mp2.pop(s2[j-n1])
            mp2[s2[j]] = 1 if s2[j] not in mp2 else mp2[s2[j]] + 1
            j += 1
        if mp1 == mp2:
            return True
        return False

