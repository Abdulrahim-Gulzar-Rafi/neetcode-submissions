class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mp1, mp2 = {}, {}
        n1, n2 = len(s1), len(s2)
        for i in s1:
            mp1[i] = 1 if i not in mp1 else mp1[i] + 1
        left, right = 0, 0
        while left < n2:
            if s2[left] in mp1:
                right = left
                while right < n2 and s2[right] in mp1:
                    mp2[s2[right]] = 1 if s2[right] not in mp2 else mp2[s2[right]] + 1
                    if len(mp1) == len(mp2) and mp1 == mp2:
                        return True
                    if mp2[s2[right]] > mp1[s2[right]]:
                        break
                    right += 1
            mp2 = {}
            left += 1
        return False
