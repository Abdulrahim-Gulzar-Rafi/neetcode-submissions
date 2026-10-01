class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        m, n = len(grid), len(grid[0])
        treasures = []
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    treasures.append([i,j])

        def bfs(x, y):
            nonlocal grid
            dq = deque()
            dq.append([x,y])
            count = -1
            while dq:
                size = len(dq)
                count += 1
                while size:
                    i, j = dq[0][0], dq[0][1]
                    dq.popleft()
                    if 0 <= i < m and 0 <= j < n and grid[i][j] > 0 or count == 0:
                        if grid[i][j] > count or count == 0:
                            if count > 0:
                                grid[i][j] = count
                            dq.append([i-1,j])
                            dq.append([i+1,j])
                            dq.append([i,j-1])
                            dq.append([i,j+1])
                    size -= 1

        for treasure in treasures:
            bfs(treasure[0], treasure[1])
