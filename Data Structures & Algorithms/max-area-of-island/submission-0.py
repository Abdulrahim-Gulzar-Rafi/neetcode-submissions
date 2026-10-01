class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        count = 0

        def dfs(i, j):
            if 0 <= i < rows and 0 <= j < cols and grid[i][j]:
                nonlocal count
                count += 1
                grid[i][j] = 0
                dfs(i + 1, j)
                dfs(i - 1, j)
                dfs(i, j + 1)
                dfs(i, j - 1)

        max_area = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    count = 0
                    dfs(r, c)
                    max_area = max(max_area, count)
        return max_area
