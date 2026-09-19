class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        left, right = 0, 0
        mp = {}
        max_substring_length = 0
        while left < n:
            while right < n:
                mp[s[right]] = 1 if s[right] not in mp else mp[s[right]] + 1

                def is_window_valid() -> bool:
                    most_frequent_count = max(mp.values())
                    to_replace = (right - left) + 1 - most_frequent_count
                    return to_replace <= k

                if is_window_valid():
                    max_substring_length = max(max_substring_length, right - left + 1)
                    right += 1
                else:
                    mp[s[left]] -= 1
                    if mp[s[left]] == 0:
                        mp.pop(s[left])
                    right += 1
                    break
            left += 1

        return max_substring_length
