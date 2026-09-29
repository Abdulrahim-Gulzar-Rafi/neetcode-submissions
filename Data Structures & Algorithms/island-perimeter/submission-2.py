class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        perimeter = 0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    if i - 1 < 0 or not grid[i-1][j]:
                        perimeter += 1
                    if i + 1 >= m or not grid[i+1][j]:
                        perimeter += 1
                    if j - 1 < 0 or not grid[i][j-1]:
                        perimeter += 1
                    if j + 1 >= n or not grid[i][j+1]:
                        perimeter += 1
        return perimeter;
