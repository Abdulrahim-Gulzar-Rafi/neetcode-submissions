class Solution:
    def solve(self, board: List[List[str]]) -> None:
        m, n = len(board), len(board[0])

        def dfs_capture(u, v):
            nonlocal board
            nonlocal m
            nonlocal n
            board[u][v] = '1'

            directions = ((1,0),(-1,0),(0,1),(0,-1))

            for x in directions:
                u2 = u
                v2 = v
                u2 += x[0]
                v2 += x[1]
                if 0 <= u2 < m and 0 <= v2 < n and board[u2][v2] == 'O':
                    dfs_capture(u2,v2)

        # first row
        for j in range(n):
            if board[0][j] == 'O':
                dfs_capture(0,j)

        # last row
        for j in range(n):
            if board[m-1][j] == 'O':
                dfs_capture(m-1,j)

        # first column
        for i in range(m):
            if board[i][0] == 'O':
                dfs_capture(i,0)

        # first column
        for i in range(m):
            if board[i][n-1] == 'O':
                dfs_capture(i,n-1)


        for i in range(m):
            for j in range(n):
                if board[i][j] == '1':
                    board[i][j] = 'O'
                else:
                    board[i][j] = 'X'


