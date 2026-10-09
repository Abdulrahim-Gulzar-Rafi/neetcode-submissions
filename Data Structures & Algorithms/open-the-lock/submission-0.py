class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        n, count = len(target), 0
        seen = set(deadends)
        dq = deque()
        dq.append("0000")
        while dq:
            size = len(dq)
            while size:
                lock = dq[0]
                dq.popleft()
                size -= 1
                if lock == target:
                    return count
                if lock in seen:
                    continue
                seen.add(lock)
                for i in range(n):
                    temp = lock
                    digit = int(temp[i]) + 1
                    if digit > 9:
                        digit = 0
                    temp = temp[:i] + str(digit) + temp[i+1:]
                    dq.append(temp)
                    temp = lock
                    digit = int(temp[i]) - 1
                    if digit < 0:
                        digit = 9
                    temp = temp[:i] + str(digit) + temp[i+1:]
                    dq.append(temp)
            count +=1
        return -1
