class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        dp = [[ [0,0,0] for i in range(n) ] for i in range(m)] # [pacific, atlantic, seen]

        def dfs_pacific(i,j):
            nonlocal dp
            nonlocal heights
            dp[i][j][0] = 1
            if dp[i][j][2]:
                return
            dp[i][j][2] = 1
            if i+1 < m and heights[i+1][j] >= heights[i][j]:
                dfs_pacific(i+1,j)
            if j+1 < n and heights[i][j+1] >= heights[i][j]:
                dfs_pacific(i,j+1)
            if j-1 >= 0 and heights[i][j-1] >= heights[i][j]:
                dfs_pacific(i,j-1)

        def dfs_atlantic(i,j): #checker
            nonlocal dp
            nonlocal heights
            dp[i][j][1] = 1
            if dp[i][j][2]:
                return
            dp[i][j][2] = 1
            if i-1 >= 0 and heights[i-1][j] >= heights[i][j]:
                dfs_atlantic(i-1,j);
            if j+1 < n and heights[i][j+1] >= heights[i][j]:
                dfs_atlantic(i,j+1)
            if j-1 >= 0 and heights[i][j-1] >= heights[i][j]:
                dfs_atlantic(i,j-1)


        # perform on the first row
        for j in range(n):
            dfs_pacific(0,j)

        # perform on the first column
        for i in range(m):
            dfs_pacific(i,0)

        # reset visited
        for i in dp:
            for j in i:
                j[2] = 0

        # perform on the last row
        for j in range(n):
            dfs_atlantic(m-1,j)

        # perform on the last column
        for i in range(m):
            dfs_atlantic(i,n-1)

        answer = []
        for i in range(m):
            for j in range(n):
                if dp[i][j][0] and dp[i][j][1]:
                    answer.append([i,j])

        return answer
