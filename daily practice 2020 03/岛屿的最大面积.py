"""
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

链接：https://leetcode-cn.com/problems/max-area-of-island
"""

# class Solution:  # passed.

#     def __init__(self):
#         self.maxArea = 0
#         self.currArea = 0

#         self.grid = None
#         self.visited = None

#         self.height = 0
#         self.width = 0

#     def search(self, i, j):
#         # The idxs should be greater than 0 since negative idxs are valid for python.
#         if not (0 <= i < self.height and 0 <= j < self.width):  #
#             return
#         # The element should be 1 and the loc should not be visited.
#         if not (self.grid[i][j] == 1 and self.visited[i][j] == 0):  #
#             return

#         # Not visited -> visited.
#         self.visited[i][j] = 1
#         self.currArea += 1

#         # >
#         self.search(i + 1, j)
#         # <
#         self.search(i - 1, j)  #
#         # v
#         self.search(i, j + 1)  #
#         # ^
#         self.search(i, j - 1)

#     def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
#         # Init for some vars.
#         self.grid = grid
#         self.height = len(grid)  #
#         self.width = len(grid[0])  #

#         # Creates a matrix with the same size as `grid` to track if the loc is visited.
#         self.visited = copy.deepcopy(self.grid)
#         for i in range(self.height):
#             for j in range(self.width):
#                 self.visited[i][j] = 0

#         for i in range(self.height):
#             for j in range(self.width):
#                 # If the element is 1 and the loc is not visited.
#                 if self.grid[i][j] == 1 and self.visited[i][j] == 0:
#                     self.search(i, j)

#                 self.maxArea = max(self.maxArea, self.currArea)

#                 self.currArea = 0  #

#         return self.maxArea

class Solution:  # modified with solution from: https://leetcode-cn.com/problems/max-area-of-island/solution/dao-yu-de-zui-da-mian-ji-by-leetcode-solution/

    def __init__(self):
        self.grid = None

        self.height = 0
        self.width = 0

    def search(self, i, j):
        # The idxs should be greater than 0 since negative idxs are valid for python.
        if not (0 <= i < self.height and 0 <= j < self.width):  #
            return 0
        # The element should be 1.
        if not (self.grid[i][j] == 1):  #
            return 0

        self.grid[i][j] = 0

        return (1
            + self.search(i + 1, j)
            + self.search(i - 1, j)
            + self.search(i, j + 1)
            + self.search(i, j - 1))

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # Init for some vars.
        self.grid = grid
        self.height = len(grid)  #
        self.width = len(grid[0])  #

        max_area = 0
        for i in range(self.height):
            for j in range(self.width):
                # If the element is 1.
                if self.grid[i][j] == 1:
                    max_area = max(max_area, self.search(i, j))

        return max_area

