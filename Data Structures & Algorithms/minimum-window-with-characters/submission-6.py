class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n1, n2 = len(s), len(t)
        if n1 < n2:
            return ""
        if n1 == n2:
            new_s = "".join(sorted(s))
            t = "".join(sorted(t))
            if new_s != t:
                return ""
            else:
                return s
        mp1, mp2 = {}, {}

        for i in t:
            mp2[i] = 1 if i not in mp2 else mp2[i] + 1


        def matching_mp() -> bool:
            if len(mp1) != len(mp2):
                return False
            for i in mp1:
                if mp2[i] > mp1[i]:
                    return False
            return True

        min_window_len = n1 + 1
        min_window = [0, n1]
        left, right = 0, 0
        while left < n1 and s[left] not in mp2:
            left += 1
            right += 1

        while left < n1:
            if s[left] not in mp2:
                left += 1
                continue
            while right < n1:
                if s[right] in mp2:
                    mp1[s[right]] = 1 if s[right] not in mp1 else mp1[s[right]] + 1

                    if matching_mp():
                        if right - left < min_window_len:
                            min_window_len = right - left
                            min_window = [left,right]
                        mp1[s[left]] -= 1
                        if mp1[s[left]] == 0:
                            mp1.pop(s[left])
                        left += 1
                        while left <= right and left < n1:
                            if s[left] in mp2:
                                break
                            left += 1
                        if matching_mp() and right - left < min_window_len:
                            min_window_len = right - left
                            min_window = [left,right]
                        right += 1
                        break
                right += 1
            if left < n1 <= right and s[left] in mp1:
                mp1[s[left]] -= 1
                if mp1[s[left]] == 0:
                    mp1.pop(s[left])
                left += 1
                if matching_mp() and right - left < min_window_len:
                    min_window_len = right - left
                    min_window = [left,right]

        if min_window_len == n1 + 1:
            return ""
        min_window_substring = s[min_window[0]: min_window[1]+1]
        return min_window_substring

