class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n1, n2 = len(s), len(t)
        if n1 < n2:
            return ""
        if n1 == n2:
            s = "".join(sorted(s))
            t = "".join(sorted(t))
            if s != t:
                return ""
            else:
                return s
        mp1, mp2 = {}, {}

        index_mp = {}
        for i in range(n1):
            index_mp[i] = s[i]

        for i in t:
            mp2[i] = 1 if i not in mp2 else mp2[i] + 1


        def matching_mp() -> bool:
            if len(mp1) != len(mp2):
                return False
            for i in mp1:
                if mp2[i] > mp1[i]:
                    return False
            return True
        
        left, right = 0, 0
        min_window_len = n1 + 1
        min_window = []

        while left < n1 and s[left] not in mp2:
            left += 1
            right += 1

        while left < n1:
            if s[left] in mp2:
                if matching_mp():
                    if (right-1) - left <= min_window_len:
                        min_window_len = (right - 1) - left
                        min_window = [left, right -1]
                else:
                    while right < n1:
                        if s[right] in mp2:
                            mp1[s[right]] = 1 if s[right] not in mp1 else mp1[s[right]] + 1
                            if matching_mp():
                                if right - left <= min_window_len:
                                    min_window_len = right - left
                                    min_window = [left, right]
                                right +=1
                                break
                        right += 1
                if s[left] in mp1:
                    mp1[s[left]] -= 1
                    if mp1[s[left]] == 0:
                        del mp1[s[left]]
            left += 1

        if min_window_len == n1 + 1:
            return ""

        return s[min_window[0]: min_window[1] +1]

