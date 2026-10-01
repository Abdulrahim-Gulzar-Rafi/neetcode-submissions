class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue = deque()
        m, n = len(grid), len(grid[0])
        visited = [[0] * n for _ in range(m)]
        traversable = {}
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    grid[i][j] = 0
                    queue.append((i, j))
                elif grid[i][j] == 1:
                    grid[i][j] = 3
                    if i not in traversable:
                        traversable[i] = {}
                    if j not in traversable[i]:
                        traversable[i][j] = False
                else:
                    grid[i][j] = -1

        if not traversable:
            return 0

        max_time = -1
        while queue:
            row, col = queue.popleft()
            if row + 1 < m and grid[row+1][col] > 0 and visited[row+1][col] == 0:
                grid[row+1][col] = grid[row][col] + 1
                max_time = max(max_time, grid[row+1][col])
                if row+1 in traversable and col in traversable[row+1]:
                    traversable[row+1][col] = True
                visited[row+1][col] = 1
                queue.append((row+1, col))
            if row - 1 >= 0 and grid[row-1][col] > 0 and visited[row-1][col] == 0:
                grid[row-1][col] = grid[row][col] + 1
                max_time = max(max_time, grid[row-1][col])
                if row-1 in traversable and col in traversable[row-1]:
                    traversable[row-1][col] = True
                visited[row-1][col] = 1
                queue.append((row-1, col))
            if col + 1 < n and grid[row][col+1] > 0 and visited[row][col+1] == 0:
                grid[row][col+1] = grid[row][col] + 1
                max_time = max(max_time, grid[row][col+1])
                if row in traversable and col+1 in traversable[row]:
                    traversable[row][col+1] = True
                visited[row][col+1] = 1
                queue.append((row, col+1))
            if col - 1 >= 0 and grid[row][col-1] > 0 and visited[row][col-1] == 0:
                grid[row][col-1] = grid[row][col] + 1
                max_time = max(max_time, grid[row][col-1])
                if row in traversable and col-1 in traversable[row]:
                    traversable[row][col-1] = True
                visited[row][col-1] = 1
                queue.append((row, col-1))

        
        for i in traversable:
            for j in traversable[i]:
                if not traversable[i][j]:
                    return -1

        return max_time
