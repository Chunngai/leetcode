"""
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。

请你返回最终形体的表面积。

 

示例 1：

输入：[[2]]
输出：10
示例 2：

输入：[[1,2],[3,4]]
输出：34
示例 3：

输入：[[1,0],[0,2]]
输出：16
示例 4：

输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：32
示例 5：

输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：46

链接：https://leetcode-cn.com/problems/surface-area-of-3d-shapes
"""

class Solution:

    def _by_loss(self, elem, i_, j_, grid):
        if i_ < 0 or j_ < 0 or i_ >= len(grid) or j_ >= len(grid):
            return 0
        else:
            return min(elem, grid[i_][j_])

    def by_loss(self, elem, i, j, grid):
        return (self._by_loss(elem, i, j + 1, grid)
            + self._by_loss(elem, i, j - 1, grid)
            + self._by_loss(elem, i + 1, j, grid)
            + self._by_loss(elem, i - 1, j, grid)
        )

    def self_loss(self, elem):
        return 2 * (elem - 1) if elem >= 1 else 0

    def surfaceArea(self, grid: List[List[int]]) -> int:
        surface = 0
        for i in range(len(grid)):
            for j in range(len(grid)):
                elem = grid[i][j]

                surface += 6 * elem - self.self_loss(elem) - self.by_loss(elem, i, j, grid)

        return surface
